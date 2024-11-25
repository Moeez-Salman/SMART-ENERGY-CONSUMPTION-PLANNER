#pragma once
#include "Information.h"
namespace SMR {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	/// <summary>
	/// Summary for addappliances
	/// </summary>
	public ref class addnewappliances : public System::Windows::Forms::Form
	{
	public:
		int no_of_app;
		int appliancewattcounter;
		int applianceCounter;
		int appliancetimeCounter;
		int ApplianceSheduleHours;
		Form^ obj;
		String^ n;
		String^ em;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	public:
		String^ p;
		addnewappliances(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		addnewappliances(Form^ obj1, String^ name, String^ email, String^ password, int no_of_appliances)
		{
			obj = obj1;
			n = name;
			em = email;
			p = password;
			no_of_app = no_of_appliances;
			InitializeComponent();
			appliancewattcounter = 1;
			applianceCounter = 1;
			appliancetimeCounter = 1;
			ApplianceSheduleHours = 1;
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~addnewappliances()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		String^ conn = "Data Source=localhost\\sqlexpress;Initial Catalog=User;Integrated Security=True";
	protected:





	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;


	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(addnewappliances::typeid));
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::CadetBlue;
			this->textBox2->Location = System::Drawing::Point(440, 530);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(514, 35);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &addnewappliances::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Control;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->ForeColor = System::Drawing::Color::CadetBlue;
			this->textBox3->Location = System::Drawing::Point(440, 667);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(514, 35);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"Enter the amont of time\r\n";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox2->Location = System::Drawing::Point(1087, 305);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(772, 491);
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LightGray;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Location = System::Drawing::Point(24, 175);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 80);
			this->button3->TabIndex = 3;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &addnewappliances::button3_Click);
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(1732, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(127, 109);
			this->button1->TabIndex = 11;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &addnewappliances::button1_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(488, 185);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(756, 55);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Enter the details of the appliance";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SkyBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(587, 810);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(309, 52);
			this->button2->TabIndex = 13;
			this->button2->Text = L"REGISTER";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &addnewappliances::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::Color::Gainsboro;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->ForeColor = System::Drawing::Color::CadetBlue;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(440, 406);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->MaxDropDownItems = 7;
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(515, 34);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &addnewappliances::comboBox1_SelectedIndexChanged);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(18, 401);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(270, 37);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Select Appliance";
			this->label2->Click += gcnew System::EventHandler(this, &addnewappliances::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(18, 524);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(300, 37);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Watts of appliance";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(18, 661);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(287, 37);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Time of appliance";
			this->label4->Click += gcnew System::EventHandler(this, &addnewappliances::label4_Click);
			// 
			// addnewappliances
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1924, 1041);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button3);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"addnewappliances";
			this->Text = L"addappliances";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &addnewappliances::addappliances_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: bool isInitialized = false;

	private: System::Void addappliances_Load(System::Object^ sender, System::EventArgs^ e) {
		if (isInitialized) return; // Ensure initialization happens only once
		isInitialized = true;

		// Clear existing items to prevent duplicates
		comboBox1->Items->Clear();

		// Add appliance options to ComboBox
		comboBox1->Items->AddRange(gcnew cli::array<String^>{
			"Fan", "Light Bulb", "Refrigerator", "Air Conditioner", "Microwave", "TV", "Washing Machine"
		});
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Hide();
		obj->Show();

	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// Set watts automatically based on selected appliance
		String^ selectedAppliance = comboBox1->Text;
		int watts = 0;

		if (selectedAppliance == "Fan") {
			watts = 75;
		}
		else if (selectedAppliance == "Light Bulb") {
			watts = 60;
		}
		else if (selectedAppliance == "Refrigerator") {
			watts = 150;
		}
		else if (selectedAppliance == "Air Conditioner") {
			watts = 2000;
		}
		else if (selectedAppliance == "Microwave") {
			watts = 1000;
		}
		else if (selectedAppliance == "TV") {
			watts = 120;
		}
		else if (selectedAppliance == "Washing Machine") {
			watts = 500;
		}

		textBox2->Text = watts.ToString(); // Update watts textbox
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {


		SMR::Information^ I = gcnew SMR::Information(this, n, em, p, no_of_app);
		this->Hide();
		I->ShowDialog();


	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}




	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// Retrieve values from text boxes
		String^ nameofappliance = comboBox1->Text;
		String^ amountofwatts = textBox2->Text;
		String^ timeofappliance = textBox3->Text;

		SqlConnection^ connect = gcnew SqlConnection(conn);

		try {
			connect->Open();

			// Generate the column names based on the counters
			String^ newColumnName = "appliance" + applianceCounter.ToString();
			String^ newColumnName1 = "ApplianceWatt" + appliancewattcounter.ToString();
			String^ newColumnName2 = "ApplianceTime" + appliancetimeCounter.ToString();
			String^ newColumnName3 = "ApplianceSheduleHours" + ApplianceSheduleHours.ToString();

			// Corrected query to add columns
			String^ alterQuery = "ALTER TABLE user_data ADD " + newColumnName + " VARCHAR(50), " +
				newColumnName1 + " FLOAT, " + newColumnName2 + " FLOAT, " + newColumnName3 + " FLOAT";
			SqlCommand^ alterCommand = gcnew SqlCommand(alterQuery, connect);
			alterCommand->ExecuteNonQuery();

			// Update user_data table, set ApplianceSheduleHours to NULL initially
			String^ updateQuery = "UPDATE user_data SET " + newColumnName + " = @nameofappliance, " +
				newColumnName1 + " = @amountofwatts, " + newColumnName2 + " = @timeofappliance, " +
				newColumnName3 + " = NULL, no_of_appliances = no_of_appliances + 1";
			SqlCommand^ updateCommand = gcnew SqlCommand(updateQuery, connect);
			updateCommand->Parameters->AddWithValue("@nameofappliance", nameofappliance);
			updateCommand->Parameters->AddWithValue("@amountofwatts", amountofwatts);
			updateCommand->Parameters->AddWithValue("@timeofappliance", timeofappliance);
			updateCommand->ExecuteNonQuery();

			// Increment the counters
			applianceCounter++;
			appliancewattcounter++;
			appliancetimeCounter++;
			ApplianceSheduleHours++;

			MessageBox::Show("Appliance data added successfully!", "Success", MessageBoxButtons::OK);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Database Error", MessageBoxButtons::OK);
		}
		finally {
			connect->Close();
		}
	}

	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}