namespace LibAvoidClient
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.add_shape = new System.Windows.Forms.Button();
            this.add_connector = new System.Windows.Forms.Button();
            this.comboShapeFrom = new System.Windows.Forms.ComboBox();
            this.comboPinFrom = new System.Windows.Forms.ComboBox();
            this.comboShapeTo = new System.Windows.Forms.ComboBox();
            this.comboPinTo = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.export_svg = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel1.BackColor = System.Drawing.Color.White;
            this.panel1.Location = new System.Drawing.Point(12, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(881, 438);
            this.panel1.TabIndex = 0;
            // 
            // add_shape
            // 
            this.add_shape.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.add_shape.Location = new System.Drawing.Point(910, 12);
            this.add_shape.Name = "add_shape";
            this.add_shape.Size = new System.Drawing.Size(127, 33);
            this.add_shape.TabIndex = 1;
            this.add_shape.Text = "add shape";
            this.add_shape.UseVisualStyleBackColor = true;
            this.add_shape.Click += new System.EventHandler(this.aggiungi_shape_click);
            // 
            // add_connector
            // 
            this.add_connector.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.add_connector.Location = new System.Drawing.Point(910, 118);
            this.add_connector.Name = "add_connector";
            this.add_connector.Size = new System.Drawing.Size(127, 33);
            this.add_connector.TabIndex = 2;
            this.add_connector.Text = "add connector";
            this.add_connector.UseVisualStyleBackColor = true;
            this.add_connector.Click += new System.EventHandler(this.aggiungi_connettore_click);
            // 
            // comboShapeFrom
            // 
            this.comboShapeFrom.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.comboShapeFrom.FormattingEnabled = true;
            this.comboShapeFrom.Location = new System.Drawing.Point(945, 209);
            this.comboShapeFrom.Name = "comboShapeFrom";
            this.comboShapeFrom.Size = new System.Drawing.Size(92, 21);
            this.comboShapeFrom.TabIndex = 3;
            // 
            // comboPinFrom
            // 
            this.comboPinFrom.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.comboPinFrom.FormattingEnabled = true;
            this.comboPinFrom.Items.AddRange(new object[] {
            "All",
            "Up",
            "Down",
            "Left",
            "Right"});
            this.comboPinFrom.Location = new System.Drawing.Point(945, 236);
            this.comboPinFrom.Name = "comboPinFrom";
            this.comboPinFrom.Size = new System.Drawing.Size(92, 21);
            this.comboPinFrom.TabIndex = 4;
            // 
            // comboShapeTo
            // 
            this.comboShapeTo.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.comboShapeTo.FormattingEnabled = true;
            this.comboShapeTo.Location = new System.Drawing.Point(945, 285);
            this.comboShapeTo.Name = "comboShapeTo";
            this.comboShapeTo.Size = new System.Drawing.Size(92, 21);
            this.comboShapeTo.TabIndex = 5;
            // 
            // comboPinTo
            // 
            this.comboPinTo.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.comboPinTo.FormattingEnabled = true;
            this.comboPinTo.Items.AddRange(new object[] {
            "All",
            "Up",
            "Down",
            "Left",
            "Right"});
            this.comboPinTo.Location = new System.Drawing.Point(945, 312);
            this.comboPinTo.Name = "comboPinTo";
            this.comboPinTo.Size = new System.Drawing.Size(92, 21);
            this.comboPinTo.TabIndex = 6;
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(904, 212);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "FROM";
            // 
            // label2
            // 
            this.label2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(912, 288);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(22, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "TO";
            // 
            // export_svg
            // 
            this.export_svg.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.export_svg.Location = new System.Drawing.Point(910, 400);
            this.export_svg.Name = "export_svg";
            this.export_svg.Size = new System.Drawing.Size(127, 33);
            this.export_svg.TabIndex = 9;
            this.export_svg.Text = "export SVG..";
            this.export_svg.UseVisualStyleBackColor = true;
            this.export_svg.Click += new System.EventHandler(this.export_svg_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1049, 462);
            this.Controls.Add(this.export_svg);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboPinTo);
            this.Controls.Add(this.comboShapeTo);
            this.Controls.Add(this.comboPinFrom);
            this.Controls.Add(this.comboShapeFrom);
            this.Controls.Add(this.add_connector);
            this.Controls.Add(this.add_shape);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button add_shape;
        private System.Windows.Forms.Button add_connector;
        private System.Windows.Forms.ComboBox comboShapeFrom;
        private System.Windows.Forms.ComboBox comboPinFrom;
        private System.Windows.Forms.ComboBox comboShapeTo;
        private System.Windows.Forms.ComboBox comboPinTo;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button export_svg;
    }
}

