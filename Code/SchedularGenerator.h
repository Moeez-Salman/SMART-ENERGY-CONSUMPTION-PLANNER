#pragma once

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
	public ref class SchedularGenerator : public System::Windows::Forms::Form
	{
	public:
		String^ em;
	private: System::Windows::Forms::Button^ button2;
	public:
		Form^ obj1;
		SchedularGenerator(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		SchedularGenerator(Form^ obj, String^ email)
		{
			em = email;
			obj1 = obj;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SchedularGenerator()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SchedularGenerator::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::Gainsboro;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(31, 310);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(1861, 586);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SchedularGenerator::dataGridView1_CellContentClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(770, 200);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(353, 42);
			this->label1->TabIndex = 3;
			this->label1->Text = L"YOUR SCHEDULE";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gainsboro;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(31, 190);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 80);
			this->button1->TabIndex = 4;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &SchedularGenerator::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SkyBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(741, 902);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(428, 53);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Generate";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &SchedularGenerator::button2_Click);
			// 
			// SchedularGenerator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"SchedularGenerator";
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &SchedularGenerator::MyForm1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Hide();
		obj1->Show();


	}
		   void buttonLoad_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   LoadAppliancesFromDatabase();
		   }

		   void LoadAppliancesFromDatabase()
		   {
			   // Connection string (update with your database credentials)
			   String^ connectionString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=User;Integrated Security=True";
			   SqlConnection^ connection = gcnew SqlConnection(connectionString);

			   try
			   {
				   connection->Open();
				   String^ query = L"SELECT * FROM user_data WHERE Email_phonenno = @Email";  // Select all columns
				   SqlCommand^ command = gcnew SqlCommand(query, connection);
				   command->Parameters->AddWithValue(L"@Email", em);

				   SqlDataAdapter^ adapter = gcnew SqlDataAdapter(command);
				   DataTable^ table = gcnew DataTable();
				   adapter->Fill(table);

				   // Check if the query returned any data
				   if (table->Rows->Count > 0)
				   {
					   // Create a new DataTable to store appliances and their schedule hours as rows
					   DataTable^ newTable = gcnew DataTable();
					   newTable->Columns->Add(L"Appliance");
					   newTable->Columns->Add(L"ApplianceHours");

					   // Loop through each row in the DataTable
					   for (int i = 0; i < table->Rows->Count; ++i)
					   {
						   // Access the row using the DataRow object
						   DataRow^ row = table->Rows[i];

						   // Loop through the columns of the row
						   for (int col = 0; col < table->Columns->Count; ++col)
						   {
							   String^ columnName = table->Columns[col]->ColumnName;

							   // Check if the column name starts with "appliance"
							   if (columnName->StartsWith("appliance"))
							   {
								   // Check if the value in the column is not DBNull
								   if (row[col] != DBNull::Value)
								   {
									   String^ appliance = row[col]->ToString();
									   double applianceHours = 0;

									   // Look for the corresponding ApplianceScheduleHours column
									   String^ scheduleColumnName = "ApplianceSheduleHours" + columnName->Substring(columnName->Length - 1);
									   if (table->Columns->Contains(scheduleColumnName))
									   {
										   // Get the schedule hours from the corresponding column
										   if (row[scheduleColumnName] != DBNull::Value)
										   {
											   applianceHours = (double)row[scheduleColumnName];
										   }
									   }

									   // Add the appliance and schedule hours with "hours" to the new table
									   String^ hoursText = applianceHours.ToString("F2") + " hours"; // Format as "X.XX hours"
									   newTable->Rows->Add(appliance, hoursText);
								   }
							   }
						   }
					   }

					   // Set the new table as the DataSource for the DataGridView
					   dataGridView1->DataSource = newTable;
				   }
				   else
				   {
					   dataGridView1->DataSource = nullptr;
					   MessageBox::Show(L"No appliances found.");
				   }
			   }
			   catch (Exception^ ex)
			   {
				   MessageBox::Show(L"Error: " + ex->Message);
			   }
			   finally
			   {
				   connection->Close();
			   }
		   }


	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {






	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		LoadAppliancesFromDatabase();

	}
	};
}
