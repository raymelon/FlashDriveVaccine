#pragma once

namespace FlashDriveVaccine {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::IO;
	using namespace System::Security::AccessControl;
	using namespace System::Security::Principal;
	using namespace System::Text::RegularExpressions;
	//using namespace System::

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			array<DriveInfo^>^ letters = DriveInfo::GetDrives();
			comboBoxDriveLetter->Items->Clear();

			for each (DriveInfo^ letter in letters)
			{
				if (letter->IsReady && letter->DriveType == DriveType::Removable)
				{
					String^ label = letter->VolumeLabel;
					comboBoxDriveLetter->Items->Add(letter + "(" + label + ")");
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ProgressBar^  progressVaccination;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Button^  buttonStartVaccinating;
	private: System::Windows::Forms::ComboBox^  comboBoxDriveLetter;
	
	private: System::Windows::Forms::Label^  labelDriveLetter;
	private: System::Windows::Forms::Label^  labelDriveName;
	private: System::Windows::Forms::TextBox^  textBoxDriveName;
	private: System::Windows::Forms::Label^  labelRootName;
	private: System::Windows::Forms::TextBox^  textBoxRootName;


	private: String^ driveLetter;
	private: String^ driveName;
	private: String^ rootFolder;
	private: System::Windows::Forms::RichTextBox^  richTextBoxConsole;

	private: System::Windows::Forms::Label^  labelStatus;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  licensesToolStripMenuItem;








	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->progressVaccination = (gcnew System::Windows::Forms::ProgressBar());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->buttonStartVaccinating = (gcnew System::Windows::Forms::Button());
			this->comboBoxDriveLetter = (gcnew System::Windows::Forms::ComboBox());
			this->labelDriveLetter = (gcnew System::Windows::Forms::Label());
			this->labelDriveName = (gcnew System::Windows::Forms::Label());
			this->textBoxDriveName = (gcnew System::Windows::Forms::TextBox());
			this->labelRootName = (gcnew System::Windows::Forms::Label());
			this->textBoxRootName = (gcnew System::Windows::Forms::TextBox());
			this->richTextBoxConsole = (gcnew System::Windows::Forms::RichTextBox());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->licensesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// progressVaccination
			// 
			this->progressVaccination->Location = System::Drawing::Point(21, 306);
			this->progressVaccination->Name = L"progressVaccination";
			this->progressVaccination->Size = System::Drawing::Size(217, 23);
			this->progressVaccination->TabIndex = 0;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// buttonStartVaccinating
			// 
			this->buttonStartVaccinating->Enabled = false;
			this->buttonStartVaccinating->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonStartVaccinating->Location = System::Drawing::Point(21, 169);
			this->buttonStartVaccinating->Name = L"buttonStartVaccinating";
			this->buttonStartVaccinating->Size = System::Drawing::Size(217, 41);
			this->buttonStartVaccinating->TabIndex = 1;
			this->buttonStartVaccinating->Text = L"Vaccinate Now";
			this->buttonStartVaccinating->UseVisualStyleBackColor = true;
			this->buttonStartVaccinating->Click += gcnew System::EventHandler(this, &MyForm::buttonStartVaccinating_Click);
			// 
			// comboBoxDriveLetter
			// 
			this->comboBoxDriveLetter->BackColor = System::Drawing::SystemColors::Info;
			this->comboBoxDriveLetter->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxDriveLetter->FormattingEnabled = true;
			this->comboBoxDriveLetter->Location = System::Drawing::Point(21, 50);
			this->comboBoxDriveLetter->Name = L"comboBoxDriveLetter";
			this->comboBoxDriveLetter->Size = System::Drawing::Size(218, 21);
			this->comboBoxDriveLetter->Sorted = true;
			this->comboBoxDriveLetter->TabIndex = 2;
			this->comboBoxDriveLetter->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxDriveLetter_SelectedIndexChanged);
			// 
			// labelDriveLetter
			// 
			this->labelDriveLetter->AutoSize = true;
			this->labelDriveLetter->Location = System::Drawing::Point(18, 34);
			this->labelDriveLetter->Name = L"labelDriveLetter";
			this->labelDriveLetter->Size = System::Drawing::Size(115, 13);
			this->labelDriveLetter->TabIndex = 3;
			this->labelDriveLetter->Text = L"Select removable drive";
			// 
			// labelDriveName
			// 
			this->labelDriveName->AutoSize = true;
			this->labelDriveName->Location = System::Drawing::Point(18, 79);
			this->labelDriveName->Name = L"labelDriveName";
			this->labelDriveName->Size = System::Drawing::Size(119, 13);
			this->labelDriveName->TabIndex = 4;
			this->labelDriveName->Text = L"Enter a new drive name";
			// 
			// textBoxDriveName
			// 
			this->textBoxDriveName->BackColor = System::Drawing::SystemColors::Info;
			this->textBoxDriveName->Location = System::Drawing::Point(21, 95);
			this->textBoxDriveName->MaxLength = 256;
			this->textBoxDriveName->Name = L"textBoxDriveName";
			this->textBoxDriveName->Size = System::Drawing::Size(217, 20);
			this->textBoxDriveName->TabIndex = 5;
			this->textBoxDriveName->Text = L"IMMUNIZED";
			// 
			// labelRootName
			// 
			this->labelRootName->AutoSize = true;
			this->labelRootName->Location = System::Drawing::Point(18, 127);
			this->labelRootName->Name = L"labelRootName";
			this->labelRootName->Size = System::Drawing::Size(142, 13);
			this->labelRootName->TabIndex = 6;
			this->labelRootName->Text = L"Enter your drive\'s main folder";
			// 
			// textBoxRootName
			// 
			this->textBoxRootName->BackColor = System::Drawing::SystemColors::Info;
			this->textBoxRootName->Location = System::Drawing::Point(21, 143);
			this->textBoxRootName->MaxLength = 256;
			this->textBoxRootName->Name = L"textBoxRootName";
			this->textBoxRootName->Size = System::Drawing::Size(217, 20);
			this->textBoxRootName->TabIndex = 7;
			this->textBoxRootName->Text = L"ROOT2";
			// 
			// richTextBoxConsole
			// 
			this->richTextBoxConsole->BackColor = System::Drawing::SystemColors::Info;
			this->richTextBoxConsole->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBoxConsole->Location = System::Drawing::Point(21, 216);
			this->richTextBoxConsole->Name = L"richTextBoxConsole";
			this->richTextBoxConsole->ReadOnly = true;
			this->richTextBoxConsole->Size = System::Drawing::Size(217, 84);
			this->richTextBoxConsole->TabIndex = 8;
			this->richTextBoxConsole->Text = L"Welcome to Flash Drive Vaccine!";
			// 
			// labelStatus
			// 
			this->labelStatus->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->labelStatus->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->labelStatus->Location = System::Drawing::Point(0, 348);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(261, 15);
			this->labelStatus->TabIndex = 10;
			this->labelStatus->Text = L"No drive selected.";
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripStyle = System::Windows::Forms::ToolStripGripStyle::Visible;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->aboutToolStripMenuItem,
					this->helpToolStripMenuItem, this->licensesToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(261, 24);
			this->menuStrip1->TabIndex = 11;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::helpToolStripMenuItem_Click);
			// 
			// licensesToolStripMenuItem
			// 
			this->licensesToolStripMenuItem->Name = L"licensesToolStripMenuItem";
			this->licensesToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->licensesToolStripMenuItem->Text = L"Licenses";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(261, 363);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->richTextBoxConsole);
			this->Controls->Add(this->textBoxRootName);
			this->Controls->Add(this->labelRootName);
			this->Controls->Add(this->textBoxDriveName);
			this->Controls->Add(this->labelDriveName);
			this->Controls->Add(this->labelDriveLetter);
			this->Controls->Add(this->comboBoxDriveLetter);
			this->Controls->Add(this->buttonStartVaccinating);
			this->Controls->Add(this->progressVaccination);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Flash Drive Vaccine v2";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: void AddDirectorySecurity(String^ directoryName, String^ account,
			FileSystemRights rights, AccessControlType controlType) {
			
			DirectoryInfo^ dInfo = gcnew DirectoryInfo(directoryName);
			DirectorySecurity^ dSecurity = dInfo->GetAccessControl();

			//SecurityIdentifier^ everyone = gcnew SecurityIdentifier(WellKnownSidType::WorldSid, nullptr);

			dSecurity->AddAccessRule(gcnew FileSystemAccessRule(account,
				rights, controlType));
			dInfo->SetAccessControl(dSecurity);
		}

		private: System::Void executeInShell(String^ pathToMyEXE, String^ args) {

			Process^ process = gcnew Process();
			process->StartInfo->CreateNoWindow = true;
			process->StartInfo->UseShellExecute = false;
			process->StartInfo->FileName = pathToMyEXE;
			process->StartInfo->Arguments = args;
			process->StartInfo->WindowStyle = ProcessWindowStyle::Hidden;
			process->StartInfo->WindowStyle = ProcessWindowStyle::Minimized;

			process->StartInfo->RedirectStandardOutput = true;
			process->StartInfo->RedirectStandardError = true;

			process->OutputDataReceived += gcnew DataReceivedEventHandler(this, &MyForm::OutputToAppConsole);
			process->Start();

			// Asynchronously read the standard output of the spawned process. 
			// This raises OutputDataReceived events for each line of output.
			process->BeginOutputReadLine();
			process->WaitForExit();
		}
		
		delegate void outout(Object^ sender, DataReceivedEventArgs^ e);
			private: void oout(Object^ sender, DataReceivedEventArgs^ e)
			{	
				if (!String::IsNullOrEmpty(e->Data)) {
					richTextBoxConsole->Text += e->Data + "\n\n";
					richTextBoxConsole->SelectionStart = richTextBoxConsole->Text->Length;
					richTextBoxConsole->ScrollToCaret();
				}
			}

		private: void OutputToAppConsole(Object^ sender, DataReceivedEventArgs^ e) {
			//outout^ del = gcnew outout(this, &MyForm::oout);
			//del->Invoke(sender, e);
			this->Invoke(gcnew outout(this, &MyForm::oout), sender, e);
		}

		private: System::Void buttonStartVaccinating_Click(System::Object^  sender, System::EventArgs^  e) {

			progressVaccination->Value = 0;

			driveLetter = comboBoxDriveLetter->SelectedItem->ToString()[0].ToString();
			driveName = textBoxDriveName->Text;
			rootFolder = textBoxRootName->Text;

			backgroundWorker1->RunWorkerAsync(1);

			comboBoxDriveLetter->Enabled = true;
			textBoxDriveName->Enabled = true;
			textBoxRootName->Enabled = true;
			buttonStartVaccinating->Enabled = true;
		}

		private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

			if (backgroundWorker1->CancellationPending)
			{
				e->Cancel = true;
			}

			backgroundWorker1->ReportProgress(10);
			executeInShell("FORMAT.com", driveLetter + ": /y /x /Q /fs:NTFS /v:" + driveName);
			

			Directory::CreateDirectory(driveLetter + ":\\AUTORUN.inf");

			backgroundWorker1->ReportProgress(4);
			Directory::CreateDirectory(driveLetter + ":\\RECYCLER");

			backgroundWorker1->ReportProgress(4);
			Directory::CreateDirectory(driveLetter + ":\\AUTORUN.lnk");

			backgroundWorker1->ReportProgress(4);
			Directory::CreateDirectory(driveLetter + ":\\RECYCLER.lnk");

			backgroundWorker1->ReportProgress(4);
			Directory::CreateDirectory(driveLetter + ":\\" + rootFolder + ".lnk");

			backgroundWorker1->ReportProgress(4);
			Directory::CreateDirectory(driveLetter + ":\\" + rootFolder);



			backgroundWorker1->ReportProgress(6);
			executeInShell("ATTRIB", "+r +h +a " + driveLetter + ":/AUTORUN.inf");
			
			backgroundWorker1->ReportProgress(6);
			executeInShell("ATTRIB", "+r +h +a " + driveLetter + ":/AUTORUN.lnk");
			
			backgroundWorker1->ReportProgress(6);
			executeInShell("ATTRIB", "+r +h +a " + driveLetter + ":/RECYCLER.lnk");
			
			backgroundWorker1->ReportProgress(6);
			executeInShell("ATTRIB", "+r +h +a " + driveLetter + ":/RECYCLER");
			
			backgroundWorker1->ReportProgress(6);
			executeInShell("ATTRIB", "+r +h +a " + driveLetter + ":/" + rootFolder + ".lnk");



			backgroundWorker1->ReportProgress(2);
			
			String^ randomOwner = "guest";
			executeInShell("ICACLS", driveLetter + ":/AUTORUN.inf /setowner " + randomOwner + " /C /Q & pause");
			
			backgroundWorker1->ReportProgress(2);
			executeInShell("ICACLS", driveLetter + ":/RECYCLER /setowner " + randomOwner + " /C /Q");
			
			backgroundWorker1->ReportProgress(2);
			executeInShell("ICACLS", driveLetter + ":/AUTORUN.lnk /setowner " + randomOwner + " /C /Q");
			
			backgroundWorker1->ReportProgress(2);
			executeInShell("ICACLS", driveLetter + ":/RECYCLER.lnk /setowner " + randomOwner + " /C /Q");
			
			backgroundWorker1->ReportProgress(2);
			executeInShell("ICACLS", driveLetter + ":/" + rootFolder + ".lnk /setowner " + randomOwner + " /C /Q");



			backgroundWorker1->ReportProgress(5);
			
			AddDirectorySecurity(driveLetter + ":\\", "Everyone",
				FileSystemRights::Write |
				FileSystemRights::ReadExtendedAttributes |
				FileSystemRights::ReadPermissions |
				FileSystemRights::TakeOwnership
				, 
				
				AccessControlType::Deny);

			backgroundWorker1->ReportProgress(5);
			AddDirectorySecurity(driveLetter + ":\\" + rootFolder + ".lnk", "Everyone",
				FileSystemRights::FullControl, AccessControlType::Deny);

			backgroundWorker1->ReportProgress(5);
			AddDirectorySecurity(driveLetter + ":\\RECYCLER", "Everyone",
				FileSystemRights::FullControl, AccessControlType::Deny);

			backgroundWorker1->ReportProgress(5);
			AddDirectorySecurity(driveLetter + ":\\RECYCLER.lnk", "Everyone",
				FileSystemRights::FullControl, AccessControlType::Deny);

			backgroundWorker1->ReportProgress(5);
			AddDirectorySecurity(driveLetter + ":\\AUTORUN.lnk", "Everyone",
				FileSystemRights::FullControl, AccessControlType::Deny);

			backgroundWorker1->ReportProgress(5);
			AddDirectorySecurity(driveLetter + ":\\AUTORUN.inf", "Everyone",
				FileSystemRights::FullControl, AccessControlType::Deny);
			
		}

		private: System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			progressVaccination->Value += e->ProgressPercentage;

			comboBoxDriveLetter->Enabled = false;
			textBoxDriveName->Enabled = false;
			textBoxRootName->Enabled = false;
			buttonStartVaccinating->Enabled = false;

			switch (progressVaccination->Value) {
				case 10: 
					labelStatus->Text = "Formatting " + driveLetter + ":\\...";
					break;

				case 14:
					labelStatus->Text = "Creating fake malicious directories...";
					break;

				case 36:
					labelStatus->Text = "Applying file attributes...";
					break;

				case 62:
					labelStatus->Text = "Changing owner...";
					break;

				case 75:
					labelStatus->Text = "Applying access control...";
					break;

				case 100:
					labelStatus->Text = "Done.";
					break;
			}
		}

		private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {

			if (e->Cancelled)
			{
				MessageBox::Show("Vaccination cancelled.");
			}
			else
			{
				MessageBox::Show("Vaccination done!");
			}
		}	
	private: System::Void comboBoxDriveLetter_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBoxDriveLetter->SelectedItem != nullptr) {
			buttonStartVaccinating->Enabled = true;
			labelStatus->Text = "Ready.";
		}
	}
	
	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("Flash Drive Vaccine v2.0.0\nCopyright(c) 2014-2017 Raymel Francisco", "About Flash Drive Vaccine");
	}

	private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show(
			"Select Removable Drive:\n" +
			"Shows mounted removable drives.\n\n" +
			"Enter a new drive name:\n" +
			"The new drive name after reformat.\n\n" +
			"Enter your drive's main folder:\n" +
			"Acts as the drive's root where you'll save your files. " +
			"Vaccination disables write-privilege on drive's " +
			"root since it is widely targeted by the classic shortcut viruses " +
			"and other derivatives.\n\n" +
			"See README.md for more stuff.\n" +
			"Thank you for using Flash Drive Vaccine!"
			, 
			"Help"
		);
	}
};
}
