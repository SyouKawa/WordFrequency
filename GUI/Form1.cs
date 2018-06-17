using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WordFrequency_Win
{
    public partial class Form1 : Form
    {
        private bool isPath = false;
        private FileStream fs;
        private StreamReader sr;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog file = new OpenFileDialog();
            file.ShowDialog();
            try{
                this.FilePath.Text = System.IO.Path.GetFullPath(file.FileName);
                isPath = true;
            }
            catch(System.ArgumentException ex){
                MessageBox.Show("文件未找到。请重新选择要处理的问题件。");
            }
           
        }
        private void Clear_PreText(TextBox Input) {
            Input.Text = "";
        }

        private void FilePath_MouseClick(object sender, MouseEventArgs e){
            if (!isPath) Clear_PreText(this.FilePath);
        }

        private void Start_Click(object sender, EventArgs e){
            try{
                fs = new FileStream(this.FilePath.Text, FileMode.Open, FileAccess.Read);
                sr = new StreamReader(fs);
                string str = sr.ReadToEnd();
                this.Output.Text = str;
                sr.Close();
                fs.Close();
            }
            catch (System.IO.DirectoryNotFoundException ex)
            {
                MessageBox.Show("文件未找到。请重新选择要处理的问题件。");
            }
        }
    }
}
