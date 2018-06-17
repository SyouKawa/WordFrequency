namespace WordFrequency_Win
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;

        /// 清理所有正在使用的资源。
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.FileLoadButton = new System.Windows.Forms.Button();
            this.FilePath = new System.Windows.Forms.TextBox();
            this.Title = new System.Windows.Forms.Label();
            this.Start = new System.Windows.Forms.Button();
            this.frequency_choice = new System.Windows.Forms.RadioButton();
            this.Alpha_choice = new System.Windows.Forms.RadioButton();
            this.Output = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // FileLoadButton
            // 
            this.FileLoadButton.Location = new System.Drawing.Point(172, 85);
            this.FileLoadButton.Name = "FileLoadButton";
            this.FileLoadButton.Size = new System.Drawing.Size(75, 23);
            this.FileLoadButton.TabIndex = 0;
            this.FileLoadButton.Text = "浏览";
            this.FileLoadButton.UseVisualStyleBackColor = true;
            this.FileLoadButton.Click += new System.EventHandler(this.button1_Click);
            // 
            // FilePath
            // 
            this.FilePath.ForeColor = System.Drawing.SystemColors.ScrollBar;
            this.FilePath.Location = new System.Drawing.Point(18, 87);
            this.FilePath.Name = "FilePath";
            this.FilePath.Size = new System.Drawing.Size(152, 21);
            this.FilePath.TabIndex = 1;
            this.FilePath.Text = "请选择需要处理的文本文件";
            this.FilePath.MouseClick += new System.Windows.Forms.MouseEventHandler(this.FilePath_MouseClick);
            // 
            // Title
            // 
            this.Title.AutoSize = true;
            this.Title.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Title.Location = new System.Drawing.Point(13, 13);
            this.Title.Name = "Title";
            this.Title.Size = new System.Drawing.Size(235, 54);
            this.Title.TabIndex = 2;
            this.Title.Text = "WordFrequency ver.1.0\r\n词频统计 ver.1.0";
            // 
            // Start
            // 
            this.Start.Location = new System.Drawing.Point(12, 114);
            this.Start.Name = "Start";
            this.Start.Size = new System.Drawing.Size(75, 23);
            this.Start.TabIndex = 5;
            this.Start.Text = "开始处理";
            this.Start.UseVisualStyleBackColor = true;
            this.Start.Click += new System.EventHandler(this.Start_Click);
            // 
            // frequency_choice
            // 
            this.frequency_choice.AutoSize = true;
            this.frequency_choice.Location = new System.Drawing.Point(99, 117);
            this.frequency_choice.Name = "frequency_choice";
            this.frequency_choice.Size = new System.Drawing.Size(71, 16);
            this.frequency_choice.TabIndex = 6;
            this.frequency_choice.TabStop = true;
            this.frequency_choice.Text = "词频排序";
            this.frequency_choice.UseVisualStyleBackColor = true;
            // 
            // Alpha_choice
            // 
            this.Alpha_choice.AutoSize = true;
            this.Alpha_choice.Location = new System.Drawing.Point(176, 117);
            this.Alpha_choice.Name = "Alpha_choice";
            this.Alpha_choice.Size = new System.Drawing.Size(71, 16);
            this.Alpha_choice.TabIndex = 7;
            this.Alpha_choice.TabStop = true;
            this.Alpha_choice.Text = "字母排序";
            this.Alpha_choice.UseVisualStyleBackColor = true;
            // 
            // Output
            // 
            this.Output.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Output.Location = new System.Drawing.Point(286, 24);
            this.Output.Name = "Output";
            this.Output.Size = new System.Drawing.Size(443, 282);
            this.Output.TabIndex = 8;
            this.Output.Text = "label2";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(741, 315);
            this.Controls.Add(this.Output);
            this.Controls.Add(this.Alpha_choice);
            this.Controls.Add(this.frequency_choice);
            this.Controls.Add(this.Start);
            this.Controls.Add(this.Title);
            this.Controls.Add(this.FilePath);
            this.Controls.Add(this.FileLoadButton);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button FileLoadButton;
        private System.Windows.Forms.TextBox FilePath;
        private System.Windows.Forms.Label Title;
        private System.Windows.Forms.Button Start;
        private System.Windows.Forms.RadioButton frequency_choice;
        private System.Windows.Forms.RadioButton Alpha_choice;
        private System.Windows.Forms.Label Output;
    }
}

