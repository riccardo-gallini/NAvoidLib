using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using NAvoid;
using System.Drawing.Drawing2D;

namespace LibAvoidClient
{

    /// <summary>
    /// 
    /// </summary>
    public partial class Form1 : Form
    {
        private int pic_number = 0;
        private Random rand = new Random();

        private RouterFactory routerFactory = new RouterFactory();
        private Router router;

        /// <summary>
        /// <para>xx</para>
        /// </summary>
        public Dictionary<int, Shape> shapes = new Dictionary<int, Shape>();
        public IList<Connector> connectors = new List<Connector>();
                
        public Form1()
        {
            InitializeComponent();

            router = routerFactory.Create(RouterFlag.OrthogonalRouting);

            //case segmentPenalty:
            //m_routing_parameters[parameter] = 50;
            //break;
            //case fixedSharedPathPenalty:
            //m_routing_parameters[parameter] = 110;
            //break;
            //case anglePenalty:
            //m_routing_parameters[parameter] = 50;
            //break;
            //case crossingPenalty:
            //m_routing_parameters[parameter] = 200;
            //break;
            //case clusterCrossingPenalty:
            //m_routing_parameters[parameter] = 4000;
            //break;
            //case idealNudgingDistance:
            //m_routing_parameters[parameter] = 4.0;
            //break;
            //case portDirectionPenalty:
            //m_routing_parameters[parameter] = 100;
            //break;
            //default:
            //    m_routing_parameters[parameter] = 50;
            //break;
            
            
            router.SetRoutingPenalty(RoutingParameters.SegmentPenalty, 550);
            router.SetRoutingPenalty(RoutingParameters.FixedSharedPathPenalty, 0);
            router.SetRoutingPenalty(RoutingParameters.AnglePenalty, 150);
            router.SetRoutingPenalty(RoutingParameters.CrossingPenalty, 200);
            router.SetRoutingPenalty(RoutingParameters.ClusterCrossingPenalty, 0);
            router.SetRoutingPenalty(RoutingParameters.IdealNudgingDistance, 4.0);
            router.SetRoutingPenalty(RoutingParameters.PortDirectionPenalty, 10000);
            router.SetRoutingPenalty(RoutingParameters.ReverseDirectionPenalty, 0);
            router.SetRoutingPenalty(RoutingParameters.ShapeBufferDistance, 25);

            router.SetRoutingOption(RoutingOptions.nudgeOrthogonalSegmentsConnectedToShapes, false);
            router.SetRoutingOption(RoutingOptions.nudgeOrthogonalTouchingColinearSegments, false);
            router.SetRoutingOption(RoutingOptions.nudgeSharedPathsWithCommonEndPoint, false);
            router.SetRoutingOption(RoutingOptions.penaliseOrthogonalSharedPathsAtConnEnds, true);
            router.SetRoutingOption(RoutingOptions.performUnifyingNudgingPreprocessingStep, true);

            router.SetRoutingOption(RoutingOptions.improveHyperedgeRoutesMovingAddingAndDeletingJunctions, false);
            router.SetRoutingOption(RoutingOptions.improveHyperedgeRoutesMovingJunctions, false);




            panel1.Paint += PaintConnectors;
        }
        
        private void aggiungi_shape_click(object sender, EventArgs e)
        {
            pic_number++;

            var p = new Shape(pic_number);
            p.Top = rand.Next(0, panel1.ClientSize.Height - p.Height);
            p.Left = rand.Next(0, panel1.ClientSize.Width - p.Width);
            
            panel1.Controls.Add(p);
            shapes.Add(pic_number, p);
                        
            comboShapeFrom.Items.Add(pic_number.ToString());
            comboShapeTo.Items.Add(pic_number.ToString());

            p.AddToRouter(router);

            router.ProcessTransaction();

            panel1.Invalidate();
        }

        private void aggiungi_connettore_click(object sender, EventArgs e)
        {
            //validazione dati: magari la facciamo un'altra volta

            Shape shape_from = shapes[Int32.Parse(comboShapeFrom.Text)];
            Shape shape_to = shapes[Int32.Parse(comboShapeTo.Text)];
            var pin_from = comboPinFrom.Text;
            var pin_to = comboPinTo.Text;
            

            //add a connector to the router
            var conn = router.ConnectShapes(comboShapeFrom.Text+comboShapeTo.Text, shape_from.shape_ref, pin_from, shape_to.shape_ref, pin_to);

            //save for drawing
            connectors.Add(conn);

            //try checkpoint
                        
            router.ProcessTransaction();

            panel1.Invalidate();
            
        }
        
        private void PaintConnectors(object sender, PaintEventArgs e)
        {
            base.OnPaint(e);
            
            foreach (var conn in connectors)
            {
                if (conn.NeedsRepaint())
                {
                    var route = conn.DisplayRoute();
                    DrawRoute(e.Graphics, route);
                }
            }
        }

        public void DrawRoute(Graphics graphics, IList<NAvoid.Point> poly)
        {
            var last_point = poly[0];
            
            for(int i = 1; i<poly.Count; ++i)
            {
                var curr_point = poly[i];

                var x1 = (float)last_point.X();
                var y1 = (float)last_point.Y();
                var x2 = (float)curr_point.X();
                var y2 = (float)curr_point.Y();

                var pen = new Pen(Color.Black);

                if (i==poly.Count-1)
                {
                    pen.CustomEndCap = new AdjustableArrowCap(5, 5);
                }

                graphics.DrawLine(pen, x1, y1, x2, y2);
                
                last_point = curr_point;                
            }
        }

        private void export_svg_Click(object sender, EventArgs e)
        {
            router.OutputDiagramSVG("c:\\mydiagram");



        }
    }
}
