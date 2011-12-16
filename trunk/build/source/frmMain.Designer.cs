namespace hMailServer_builder
{
    partial class frmMain
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
			this.components = new System.ComponentModel.Container();
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmMain));
			this.tabsControl = new System.Windows.Forms.TabControl();
			this.tabBuild = new System.Windows.Forms.TabPage();
			this.txtVersion = new System.Windows.Forms.TextBox();
			this.lblVersion = new System.Windows.Forms.Label();
			this.lvwBuildSteps = new System.Windows.Forms.ListView();
			this.columnName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
			this.columnStep = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
			this.contextMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
			this.cmBuildSelected = new System.Windows.Forms.ToolStripMenuItem();
			this.cmBuildFromCursor = new System.Windows.Forms.ToolStripMenuItem();
			this.txtBuildNumber = new System.Windows.Forms.TextBox();
			this.lblBuildNumber = new System.Windows.Forms.Label();
			this.tabEnvironment = new System.Windows.Forms.TabPage();
			this.txtPathMSBuild = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.txtPathSubversion = new System.Windows.Forms.TextBox();
			this.lblSVNExecutable = new System.Windows.Forms.Label();
			this.txtPathInnoSetup = new System.Windows.Forms.TextBox();
			this.lblInnoSetupCompiler = new System.Windows.Forms.Label();
			this.txtPathVS8 = new System.Windows.Forms.TextBox();
			this.lblVSPath = new System.Windows.Forms.Label();
			this.txtPathSource = new System.Windows.Forms.TextBox();
			this.lblSourcePath = new System.Windows.Forms.Label();
			this.cmdStop = new System.Windows.Forms.Button();
			this.cmdStart = new System.Windows.Forms.Button();
			this.cmdClose = new System.Windows.Forms.Button();
			this.timerBuildTime = new System.Windows.Forms.Timer(this.components);
			this.lblBuildTime = new System.Windows.Forms.Label();
			this.lblBuildTimeLabel = new System.Windows.Forms.Label();
			this.lblBuildOutput = new System.Windows.Forms.Label();
			this.txtLog = new System.Windows.Forms.TextBox();
			this.tabsControl.SuspendLayout();
			this.tabBuild.SuspendLayout();
			this.contextMenu.SuspendLayout();
			this.tabEnvironment.SuspendLayout();
			this.SuspendLayout();
			// 
			// tabsControl
			// 
			this.tabsControl.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.tabsControl.Controls.Add(this.tabBuild);
			this.tabsControl.Controls.Add(this.tabEnvironment);
			this.tabsControl.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.tabsControl.Location = new System.Drawing.Point(12, 12);
			this.tabsControl.Name = "tabsControl";
			this.tabsControl.SelectedIndex = 0;
			this.tabsControl.Size = new System.Drawing.Size(723, 338);
			this.tabsControl.TabIndex = 0;
			// 
			// tabBuild
			// 
			this.tabBuild.Controls.Add(this.txtVersion);
			this.tabBuild.Controls.Add(this.lblVersion);
			this.tabBuild.Controls.Add(this.lvwBuildSteps);
			this.tabBuild.Controls.Add(this.txtBuildNumber);
			this.tabBuild.Controls.Add(this.lblBuildNumber);
			this.tabBuild.Location = new System.Drawing.Point(4, 22);
			this.tabBuild.Name = "tabBuild";
			this.tabBuild.Padding = new System.Windows.Forms.Padding(3);
			this.tabBuild.Size = new System.Drawing.Size(715, 312);
			this.tabBuild.TabIndex = 0;
			this.tabBuild.Text = "Build";
			this.tabBuild.UseVisualStyleBackColor = true;
			// 
			// txtVersion
			// 
			this.txtVersion.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txtVersion.Location = new System.Drawing.Point(15, 30);
			this.txtVersion.Name = "txtVersion";
			this.txtVersion.Size = new System.Drawing.Size(88, 21);
			this.txtVersion.TabIndex = 12;
			// 
			// lblVersion
			// 
			this.lblVersion.AutoSize = true;
			this.lblVersion.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblVersion.Location = new System.Drawing.Point(15, 14);
			this.lblVersion.Name = "lblVersion";
			this.lblVersion.Size = new System.Drawing.Size(42, 13);
			this.lblVersion.TabIndex = 11;
			this.lblVersion.Text = "Version";
			// 
			// lvwBuildSteps
			// 
			this.lvwBuildSteps.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.lvwBuildSteps.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnName,
            this.columnStep});
			this.lvwBuildSteps.ContextMenuStrip = this.contextMenu;
			this.lvwBuildSteps.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lvwBuildSteps.Location = new System.Drawing.Point(15, 57);
			this.lvwBuildSteps.Name = "lvwBuildSteps";
			this.lvwBuildSteps.Size = new System.Drawing.Size(684, 237);
			this.lvwBuildSteps.TabIndex = 4;
			this.lvwBuildSteps.UseCompatibleStateImageBehavior = false;
			this.lvwBuildSteps.View = System.Windows.Forms.View.Details;
			this.lvwBuildSteps.DoubleClick += new System.EventHandler(this.lvwBuildSteps_DoubleClick);
			// 
			// columnName
			// 
			this.columnName.Text = "Name";
			this.columnName.Width = 450;
			// 
			// columnStep
			// 
			this.columnStep.Text = "Status";
			this.columnStep.Width = 150;
			// 
			// contextMenu
			// 
			this.contextMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.cmBuildSelected,
            this.cmBuildFromCursor});
			this.contextMenu.Name = "contextMenu";
			this.contextMenu.Size = new System.Drawing.Size(167, 48);
			// 
			// cmBuildSelected
			// 
			this.cmBuildSelected.Name = "cmBuildSelected";
			this.cmBuildSelected.Size = new System.Drawing.Size(166, 22);
			this.cmBuildSelected.Text = "Build selected";
			this.cmBuildSelected.Click += new System.EventHandler(this.cmBuildSelected_Click);
			// 
			// cmBuildFromCursor
			// 
			this.cmBuildFromCursor.Name = "cmBuildFromCursor";
			this.cmBuildFromCursor.Size = new System.Drawing.Size(166, 22);
			this.cmBuildFromCursor.Text = "Build from cursor";
			this.cmBuildFromCursor.Click += new System.EventHandler(this.cmBuildFromCursor_Click);
			// 
			// txtBuildNumber
			// 
			this.txtBuildNumber.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.txtBuildNumber.Location = new System.Drawing.Point(115, 30);
			this.txtBuildNumber.Name = "txtBuildNumber";
			this.txtBuildNumber.Size = new System.Drawing.Size(88, 21);
			this.txtBuildNumber.TabIndex = 3;
			// 
			// lblBuildNumber
			// 
			this.lblBuildNumber.AutoSize = true;
			this.lblBuildNumber.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblBuildNumber.Location = new System.Drawing.Point(112, 14);
			this.lblBuildNumber.Name = "lblBuildNumber";
			this.lblBuildNumber.Size = new System.Drawing.Size(68, 13);
			this.lblBuildNumber.TabIndex = 2;
			this.lblBuildNumber.Text = "Build number";
			// 
			// tabEnvironment
			// 
			this.tabEnvironment.Controls.Add(this.txtPathMSBuild);
			this.tabEnvironment.Controls.Add(this.label1);
			this.tabEnvironment.Controls.Add(this.txtPathSubversion);
			this.tabEnvironment.Controls.Add(this.lblSVNExecutable);
			this.tabEnvironment.Controls.Add(this.txtPathInnoSetup);
			this.tabEnvironment.Controls.Add(this.lblInnoSetupCompiler);
			this.tabEnvironment.Controls.Add(this.txtPathVS8);
			this.tabEnvironment.Controls.Add(this.lblVSPath);
			this.tabEnvironment.Controls.Add(this.txtPathSource);
			this.tabEnvironment.Controls.Add(this.lblSourcePath);
			this.tabEnvironment.Location = new System.Drawing.Point(4, 22);
			this.tabEnvironment.Name = "tabEnvironment";
			this.tabEnvironment.Padding = new System.Windows.Forms.Padding(3);
			this.tabEnvironment.Size = new System.Drawing.Size(715, 312);
			this.tabEnvironment.TabIndex = 1;
			this.tabEnvironment.Text = "Environment";
			this.tabEnvironment.UseVisualStyleBackColor = true;
			// 
			// txtPathMSBuild
			// 
			this.txtPathMSBuild.Location = new System.Drawing.Point(17, 120);
			this.txtPathMSBuild.Name = "txtPathMSBuild";
			this.txtPathMSBuild.Size = new System.Drawing.Size(292, 21);
			this.txtPathMSBuild.TabIndex = 11;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(14, 104);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(68, 13);
			this.label1.TabIndex = 10;
			this.label1.Text = "MSBuild path";
			// 
			// txtPathSubversion
			// 
			this.txtPathSubversion.Location = new System.Drawing.Point(17, 219);
			this.txtPathSubversion.Name = "txtPathSubversion";
			this.txtPathSubversion.Size = new System.Drawing.Size(292, 21);
			this.txtPathSubversion.TabIndex = 9;
			// 
			// lblSVNExecutable
			// 
			this.lblSVNExecutable.AutoSize = true;
			this.lblSVNExecutable.Location = new System.Drawing.Point(14, 203);
			this.lblSVNExecutable.Name = "lblSVNExecutable";
			this.lblSVNExecutable.Size = new System.Drawing.Size(116, 13);
			this.lblSVNExecutable.TabIndex = 8;
			this.lblSVNExecutable.Text = "Subversion executable";
			// 
			// txtPathInnoSetup
			// 
			this.txtPathInnoSetup.Location = new System.Drawing.Point(17, 169);
			this.txtPathInnoSetup.Name = "txtPathInnoSetup";
			this.txtPathInnoSetup.Size = new System.Drawing.Size(292, 21);
			this.txtPathInnoSetup.TabIndex = 7;
			// 
			// lblInnoSetupCompiler
			// 
			this.lblInnoSetupCompiler.AutoSize = true;
			this.lblInnoSetupCompiler.Location = new System.Drawing.Point(14, 153);
			this.lblInnoSetupCompiler.Name = "lblInnoSetupCompiler";
			this.lblInnoSetupCompiler.Size = new System.Drawing.Size(104, 13);
			this.lblInnoSetupCompiler.TabIndex = 6;
			this.lblInnoSetupCompiler.Text = "Inno Setup Compiler";
			// 
			// txtPathVS8
			// 
			this.txtPathVS8.Location = new System.Drawing.Point(17, 75);
			this.txtPathVS8.Name = "txtPathVS8";
			this.txtPathVS8.Size = new System.Drawing.Size(292, 21);
			this.txtPathVS8.TabIndex = 3;
			// 
			// lblVSPath
			// 
			this.lblVSPath.AutoSize = true;
			this.lblVSPath.Location = new System.Drawing.Point(14, 59);
			this.lblVSPath.Name = "lblVSPath";
			this.lblVSPath.Size = new System.Drawing.Size(92, 13);
			this.lblVSPath.TabIndex = 2;
			this.lblVSPath.Text = "Visual Studio path";
			// 
			// txtPathSource
			// 
			this.txtPathSource.Location = new System.Drawing.Point(17, 27);
			this.txtPathSource.Name = "txtPathSource";
			this.txtPathSource.Size = new System.Drawing.Size(292, 21);
			this.txtPathSource.TabIndex = 1;
			// 
			// lblSourcePath
			// 
			this.lblSourcePath.AutoSize = true;
			this.lblSourcePath.Location = new System.Drawing.Point(14, 11);
			this.lblSourcePath.Name = "lblSourcePath";
			this.lblSourcePath.Size = new System.Drawing.Size(65, 13);
			this.lblSourcePath.TabIndex = 0;
			this.lblSourcePath.Text = "Source path";
			// 
			// cmdStop
			// 
			this.cmdStop.Enabled = false;
			this.cmdStop.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.cmdStop.Location = new System.Drawing.Point(109, 614);
			this.cmdStop.Name = "cmdStop";
			this.cmdStop.Size = new System.Drawing.Size(91, 22);
			this.cmdStop.TabIndex = 8;
			this.cmdStop.Text = "Sto&p";
			this.cmdStop.UseVisualStyleBackColor = true;
			this.cmdStop.Click += new System.EventHandler(this.cmdStop_Click);
			// 
			// cmdStart
			// 
			this.cmdStart.Font = new System.Drawing.Font("Tahoma", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.cmdStart.Location = new System.Drawing.Point(12, 614);
			this.cmdStart.Name = "cmdStart";
			this.cmdStart.Size = new System.Drawing.Size(91, 22);
			this.cmdStart.TabIndex = 5;
			this.cmdStart.Text = "&Start";
			this.cmdStart.UseVisualStyleBackColor = true;
			this.cmdStart.Click += new System.EventHandler(this.cmdRun_Click);
			// 
			// cmdClose
			// 
			this.cmdClose.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.cmdClose.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.cmdClose.Location = new System.Drawing.Point(641, 614);
			this.cmdClose.Name = "cmdClose";
			this.cmdClose.Size = new System.Drawing.Size(94, 23);
			this.cmdClose.TabIndex = 1;
			this.cmdClose.Text = "&Close";
			this.cmdClose.UseVisualStyleBackColor = true;
			this.cmdClose.Click += new System.EventHandler(this.cmdCLose_Click);
			// 
			// timerBuildTime
			// 
			this.timerBuildTime.Interval = 1000;
			this.timerBuildTime.Tick += new System.EventHandler(this.timerBuildTime_Tick);
			// 
			// lblBuildTime
			// 
			this.lblBuildTime.AutoSize = true;
			this.lblBuildTime.Location = new System.Drawing.Point(175, 353);
			this.lblBuildTime.Name = "lblBuildTime";
			this.lblBuildTime.Size = new System.Drawing.Size(0, 13);
			this.lblBuildTime.TabIndex = 14;
			// 
			// lblBuildTimeLabel
			// 
			this.lblBuildTimeLabel.AutoSize = true;
			this.lblBuildTimeLabel.Location = new System.Drawing.Point(107, 353);
			this.lblBuildTimeLabel.Name = "lblBuildTimeLabel";
			this.lblBuildTimeLabel.Size = new System.Drawing.Size(55, 13);
			this.lblBuildTimeLabel.TabIndex = 13;
			this.lblBuildTimeLabel.Text = "Build time:";
			// 
			// lblBuildOutput
			// 
			this.lblBuildOutput.AutoSize = true;
			this.lblBuildOutput.Location = new System.Drawing.Point(13, 353);
			this.lblBuildOutput.Name = "lblBuildOutput";
			this.lblBuildOutput.Size = new System.Drawing.Size(63, 13);
			this.lblBuildOutput.TabIndex = 12;
			this.lblBuildOutput.Text = "Build output";
			// 
			// txtLog
			// 
			this.txtLog.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.txtLog.BackColor = System.Drawing.Color.Black;
			this.txtLog.BorderStyle = System.Windows.Forms.BorderStyle.None;
			this.txtLog.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
			this.txtLog.ForeColor = System.Drawing.Color.White;
			this.txtLog.Location = new System.Drawing.Point(12, 370);
			this.txtLog.Multiline = true;
			this.txtLog.Name = "txtLog";
			this.txtLog.ReadOnly = true;
			this.txtLog.ScrollBars = System.Windows.Forms.ScrollBars.Both;
			this.txtLog.Size = new System.Drawing.Size(723, 238);
			this.txtLog.TabIndex = 11;
			// 
			// frmMain
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.CancelButton = this.cmdClose;
			this.ClientSize = new System.Drawing.Size(747, 648);
			this.Controls.Add(this.lblBuildTime);
			this.Controls.Add(this.lblBuildTimeLabel);
			this.Controls.Add(this.cmdStop);
			this.Controls.Add(this.lblBuildOutput);
			this.Controls.Add(this.cmdStart);
			this.Controls.Add(this.cmdClose);
			this.Controls.Add(this.txtLog);
			this.Controls.Add(this.tabsControl);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.MaximizeBox = false;
			this.Name = "frmMain";
			this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
			this.Text = "hMailServer Builder";
			this.Load += new System.EventHandler(this.frmMain_Load);
			this.tabsControl.ResumeLayout(false);
			this.tabBuild.ResumeLayout(false);
			this.tabBuild.PerformLayout();
			this.contextMenu.ResumeLayout(false);
			this.tabEnvironment.ResumeLayout(false);
			this.tabEnvironment.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TabControl tabsControl;
        private System.Windows.Forms.TabPage tabBuild;
        private System.Windows.Forms.TabPage tabEnvironment;
        private System.Windows.Forms.Label lblSourcePath;
        private System.Windows.Forms.TextBox txtPathSource;
        private System.Windows.Forms.TextBox txtBuildNumber;
        private System.Windows.Forms.Label lblBuildNumber;
        private System.Windows.Forms.Button cmdClose;
        private System.Windows.Forms.ListView lvwBuildSteps;
        private System.Windows.Forms.ColumnHeader columnName;
        private System.Windows.Forms.ColumnHeader columnStep;
		private System.Windows.Forms.Button cmdStart;
        private System.Windows.Forms.TextBox txtPathVS8;
        private System.Windows.Forms.Label lblVSPath;
        private System.Windows.Forms.TextBox txtPathInnoSetup;
        private System.Windows.Forms.Label lblInnoSetupCompiler;
        private System.Windows.Forms.Button cmdStop;
        private System.Windows.Forms.ContextMenuStrip contextMenu;
        private System.Windows.Forms.ToolStripMenuItem cmBuildSelected;
        private System.Windows.Forms.ToolStripMenuItem cmBuildFromCursor;
		private System.Windows.Forms.Timer timerBuildTime;
        private System.Windows.Forms.TextBox txtVersion;
        private System.Windows.Forms.Label lblVersion;
        private System.Windows.Forms.TextBox txtPathSubversion;
        private System.Windows.Forms.Label lblSVNExecutable;
		private System.Windows.Forms.Label lblBuildTime;
		private System.Windows.Forms.Label lblBuildTimeLabel;
		private System.Windows.Forms.Label lblBuildOutput;
		private System.Windows.Forms.TextBox txtLog;
		private System.Windows.Forms.TextBox txtPathMSBuild;
		private System.Windows.Forms.Label label1;
    }
}

