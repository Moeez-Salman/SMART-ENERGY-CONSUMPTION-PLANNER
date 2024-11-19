#pragma once
#include "Information.h"
#include "SchedularGenerator.h"
namespace SMR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class Plan : public System::Windows::Forms::Form
	{
	public:
		Form^ obj1;
		String^ n;
		String^ em;
		String^ p;
		int no_of_app;
		Plan(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Plan(Form^ obj,String^ name,String^ email,String^ password,int no_of_appliances)
		{
			obj1 = obj;
			n = name;
			em = email;
			p = password;
			no_of_app = no_of_appliances;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Plan()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		String^ conn = "Data Source=localhost\\sqlexpress;Initial Catalog=User;Integrated Security=True";
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	protected:
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker2;


	private: System::Windows::Forms::PictureBox^ pictureBox3;

	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::LinkLabel^ linkLabel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;






	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Plan::typeid));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Plan::backgroundWorker1_DoWork);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->Location = System::Drawing::Point(720, 354);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(515, 441);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SkyBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->Location = System::Drawing::Point(854, 866);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(282, 48);
			this->button2->TabIndex = 4;
			this->button2->Text = L"GENERATE PLAN\r\n";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Plan::button2_Click);
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->Location = System::Drawing::Point(317, 529);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(0, 13);
			this->linkLabel2->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(824, 264);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(299, 33);
			this->label1->TabIndex = 8;
			this->label1->Text = L"GENERATE A PLAN";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &Plan::label1_Click_2);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightGray;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(25, 181);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 80);
			this->button1->TabIndex = 9;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Plan::button1_Click);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Location = System::Drawing::Point(1765, 24);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(127, 109);
			this->button3->TabIndex = 10;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Plan::button3_Click);
			// 
			// Plan
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->linkLabel2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox3);
			this->Name = L"Plan";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &Plan::MyForm1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void GenerateSchedule() {
	SqlConnection^ connect = gcnew SqlConnection(conn);

	try {
		connect->Open();

		// Fetch energy rate from the database
		String^ energyRateQuery = "SELECT Energy_Watts FROM user_data WHERE Email_phonenno = @userEmail";
		SqlCommand^ energyRateCommand = gcnew SqlCommand(energyRateQuery, connect);
		energyRateCommand->Parameters->AddWithValue("@userEmail", em);
		SqlDataReader^ energyRateReader = energyRateCommand->ExecuteReader();

		double energyRate = 0.0;
		if (energyRateReader->Read()) {
			energyRate = Convert::ToDouble(energyRateReader["Energy_Watts"]);
		}
		energyRateReader->Close();

		// Fetch the user's monthly budget
		String^ budgetQuery = "SELECT Budget FROM user_data WHERE Email_phonenno = @userEmail";
		SqlCommand^ budgetCommand = gcnew SqlCommand(budgetQuery, connect);
		budgetCommand->Parameters->AddWithValue("@userEmail", em);
		SqlDataReader^ budgetReader = budgetCommand->ExecuteReader();

		double monthlyBudget = 0.0;
		if (budgetReader->Read()) {
			monthlyBudget = Convert::ToDouble(budgetReader["Budget"]);
		}
		budgetReader->Close();

		// Calculate daily budget
		double dailyBudget = monthlyBudget / 30.0;

		// Validate the number of appliances
		if (no_of_app <= 0) {
			MessageBox::Show("Invalid number of appliances!", "Error", MessageBoxButtons::OK);
			return;
		}

		// Dynamically construct the SELECT query
		String^ selectQuery = "SELECT ";
		for (int i = 1; i <= no_of_app; i++) {
			selectQuery += "appliance" + i.ToString() + ", ApplianceWatt" + i.ToString() + ", ApplianceTime" + i.ToString();
			if (i != no_of_app) {
				selectQuery += ", ";
			}
		}
		selectQuery += " FROM user_data WHERE Email_phonenno = @userEmail";

		SqlCommand^ selectCommand = gcnew SqlCommand(selectQuery, connect);
		selectCommand->Parameters->AddWithValue("@userEmail", em);

		SqlDataReader^ reader = selectCommand->ExecuteReader();

		// Arrays to store data
		array<String^>^ applianceNames = gcnew array<String^>(no_of_app);
		array<int>^ wattages = gcnew array<int>(no_of_app);
		array<int>^ runtimes = gcnew array<int>(no_of_app);
		array<double>^ applianceCosts = gcnew array<double>(no_of_app);

		int index = 0;
		if (reader->Read()) {
			for (int i = 1; i <= no_of_app; i++) {
				applianceNames[index] = reader["appliance" + i.ToString()]->ToString();
				wattages[index] = Convert::ToInt32(reader["ApplianceWatt" + i.ToString()]);
				runtimes[index] = Convert::ToInt32(reader["ApplianceTime" + i.ToString()]);
				index++;
			}
		}
		reader->Close();

		// Calculate total appliance cost
		double totalCost = 0.0;
		for (int i = 0; i < no_of_app; i++) {
			double totalEnergyConsumption = (wattages[i] * runtimes[i]) / 1000.0; // kWh
			double estimatedCost = totalEnergyConsumption * energyRate; // Estimated cost using dynamic energy rate
			applianceCosts[i] = estimatedCost;
			totalCost += estimatedCost;
		}

		// Check if the total cost exceeds the daily budget
		if (totalCost > dailyBudget) {
			// Adjust scheduled hours if total cost exceeds daily budget
			double scalingFactor = dailyBudget / totalCost; // Calculate scaling factor

			for (int i = 0; i < no_of_app; i++) {
				double adjustedHours = runtimes[i] * scalingFactor; // Scale down the runtime
				int scheduledHours = (int)(adjustedHours); // Convert to integer
				// Update the database with the new scheduled hours
				String^ updateQuery = "UPDATE user_data SET ApplianceSheduleHours" + (i + 1).ToString() + " = @scheduledHours WHERE Email_phonenno = @userEmail";
				SqlCommand^ updateCommand = gcnew SqlCommand(updateQuery, connect);
				updateCommand->Parameters->AddWithValue("@scheduledHours", scheduledHours);
				updateCommand->Parameters->AddWithValue("@userEmail", em);
				updateCommand->ExecuteNonQuery();
			}
		}
		else {
			// If within budget, use the original runtime
			for (int i = 0; i < no_of_app; i++) {
				String^ updateQuery = "UPDATE user_data SET ApplianceSheduleHours" + (i + 1).ToString() + " = @scheduledHours WHERE Email_phonenno = @userEmail";
				SqlCommand^ updateCommand = gcnew SqlCommand(updateQuery, connect);
				updateCommand->Parameters->AddWithValue("@scheduledHours", runtimes[i]);
				updateCommand->Parameters->AddWithValue("@userEmail", em);
				updateCommand->ExecuteNonQuery();
			}
		}

		MessageBox::Show("Schedule generated successfully!", "Success", MessageBoxButtons::OK);

		SMR::SchedularGenerator^ sg = gcnew SMR::SchedularGenerator(this,em);
		this->Hide();
		sg->ShowDialog();

	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message, "Database Error", MessageBoxButtons::OK);
	}
	finally {
		connect->Close();
	}
}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		GenerateSchedule();
		
	}
	private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		obj1->Show();
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	SMR::Information^ i = gcnew SMR::Information(this,n,em,p,no_of_app);
	this->Hide();
	i->ShowDialog();

}
};
}
