#pragma once
#include "Information.h"
#include "ViewDetails.h"
#include "addnewappliances.h"
#include <cliext/vector>

namespace SMR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	public ref class viewappliances : public System::Windows::Forms::Form
	{
	public:
		Form^ obj;
		String^ n;
		String^ em;
		String^ p;
		int no_of_app;

		viewappliances(void)
		{
			InitializeComponent();
		}

		viewappliances(Form^ obj1, String^ name, String^ email, String^ password, int no_of_appliances)
		{
			no_of_app = no_of_appliances;
			obj = obj1;
			n = name;
			em = email;
			p = password;
			InitializeComponent();
		}

	protected:
		~viewappliances()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::Button^ buttonBack;
		System::Windows::Forms::Button^ buttonLoad;
		System::ComponentModel::IContainer^ components;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(viewappliances::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->buttonLoad = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(828, 269);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(420, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Your Home Appliances";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::Gainsboro;
			this->dataGridView1->Location = System::Drawing::Point(12, 332);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(1880, 599);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &viewappliances::dataGridView1_CellContentClick);
			// 
			// buttonBack
			// 
			this->buttonBack->BackColor = System::Drawing::Color::SkyBlue;
			this->buttonBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->buttonBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonBack->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonBack->Location = System::Drawing::Point(50, 960);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(196, 46);
			this->buttonBack->TabIndex = 2;
			this->buttonBack->Text = L"Back";
			this->buttonBack->UseVisualStyleBackColor = false;
			this->buttonBack->Click += gcnew System::EventHandler(this, &viewappliances::buttonBack_Click);
			// 
			// buttonLoad
			// 
			this->buttonLoad->BackColor = System::Drawing::Color::SkyBlue;
			this->buttonLoad->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->buttonLoad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonLoad->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonLoad->Location = System::Drawing::Point(1673, 960);
			this->buttonLoad->Name = L"buttonLoad";
			this->buttonLoad->Size = System::Drawing::Size(219, 47);
			this->buttonLoad->TabIndex = 3;
			this->buttonLoad->Text = L"Load Appliances";
			this->buttonLoad->UseVisualStyleBackColor = false;
			this->buttonLoad->Click += gcnew System::EventHandler(this, &viewappliances::buttonLoad_Click);
			// 
			// viewappliances
			// 
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1904, 1041);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->buttonBack);
			this->Controls->Add(this->buttonLoad);
			this->Name = L"viewappliances";
			this->Text = L"View Appliances";
			this->Load += gcnew System::EventHandler(this, &viewappliances::viewappliances_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		// Event handlers
	private:
		void buttonBack_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Hide();
			obj->Show();
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
					// Create a new DataTable to store appliances as rows
					DataTable^ newTable = gcnew DataTable();
					newTable->Columns->Add(L"Appliance");

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
									// Add the appliance value to the new DataTable
									newTable->Rows->Add(row[col]);
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




	private: System::Void viewappliances_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
