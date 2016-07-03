using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing;

namespace LibAvoidClient
{
    public class Shape : PictureBox
    {
        public int Number { get; set; }

        public NAvoid.Router router;
        public NAvoid.Shape shape_ref;

        private Font SmallFont;

        public Shape(int number)
        {
            this.Width = 100;
            this.Height = 70;
            this.BorderStyle = BorderStyle.FixedSingle;
            this.BackColor = Color.AliceBlue;
            this.Font = new Font(FontFamily.GenericSansSerif, 18, FontStyle.Bold);

            this.SmallFont = new Font(FontFamily.GenericSansSerif, 8, FontStyle.Regular);
            this.Number = number;
            
            this.MouseDown += pic_MouseDown;
            this.MouseMove += pic_MouseMove;
            this.MouseUp += pic_MouseUp;
            this.Paint += pic_Paint;
                       
        }

        public void AddToRouter(NAvoid.Router _router)
        {
            this.router = _router;
            shape_ref = router.AddRectangle(Number.ToString(), this.Top, this.Left, this.Bottom, this.Right);
            shape_ref.AddPin("Up", 0.5, 0, NAvoid.Direction.Up, false, true);
            shape_ref.AddPin("Down", 0.5, 1, NAvoid.Direction.Down, false, true);
            shape_ref.AddPin("Left", 0, 0.5, NAvoid.Direction.Left, false, true);
            shape_ref.AddPin("Right", 1, 0.5, NAvoid.Direction.Right, false, true);

            shape_ref.AddPin("All", 0.501, 0.001, NAvoid.Direction.Up, false, true);
            shape_ref.AddPin("All", 0.501, 1.001, NAvoid.Direction.Down, false, true);
            shape_ref.AddPin("All", 0.001, 0.501, NAvoid.Direction.Left, false, true);
            shape_ref.AddPin("All", 1.001, 0.501, NAvoid.Direction.Right, false, true);
        }

        Point dragPoint = Point.Empty;
        Point startPoint = Point.Empty;
        bool dragging = false;
        

        private void pic_MouseDown(object sender, MouseEventArgs e)
        {
            var pic = (Shape)sender;
            startPoint = pic.Location;

            dragging = true;
            dragPoint = new Point(e.X, e.Y);
            
        }

        private void pic_MouseMove(object sender, MouseEventArgs e)
        {
            if (dragging)
            {
                var pic = (Shape)sender;
                pic.Location = new Point(pic.Location.X + e.X - dragPoint.X, pic.Location.Y + e.Y - dragPoint.Y);
            }
        }

        private void pic_MouseUp(object sender, MouseEventArgs e)
        {
            dragging = false;
            var pic = (Shape)sender;
            if (startPoint != pic.Location)
            {
                router.MoveShape(shape_ref, pic.Location.X - startPoint.X, pic.Location.Y - startPoint.Y);
                router.ProcessTransaction();
                this.FindForm().Controls["Panel1"].Invalidate();
            }
            Invalidate();
        }

        private void pic_Paint(object sender, PaintEventArgs e)
        {
            var pic = (Shape)sender;
            
            StringFormat format = new StringFormat();
            format.LineAlignment = StringAlignment.Center;
            format.Alignment = StringAlignment.Center;

            e.Graphics.DrawString(pic.Number.ToString(), pic.Font, Brushes.Black, (float)pic.Width/2, (float)pic.Height/2, format);
            e.Graphics.DrawString("(" + pic.Location.X.ToString() + "," + pic.Location.Y.ToString() + ")", pic.SmallFont, Brushes.Blue, 25, 15, format);
            
        }

    }
}
