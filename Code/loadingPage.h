#pragma once
#include "Signupform.h"

namespace SMR {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class loadingPage : public System::Windows::Forms::Form {
    public:
        loadingPage(void) {
            InitializeComponent();
        }

    protected:
        ~loadingPage() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::Timer^ timer1;
        System::Windows::Forms::Label^ loadingLabel;
        System::Windows::Forms::Timer^ typingTimer;
        System::ComponentModel::IContainer^ components;
        int textIndex = 0;
        System::String^ loadingText = "Smart Energy Consumption Planner";
        int progressCount = 0;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(loadingPage::typeid));
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->loadingLabel = (gcnew System::Windows::Forms::Label());
            this->typingTimer = (gcnew System::Windows::Forms::Timer(this->components));
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
            this->pictureBox1->Location = System::Drawing::Point(768, 293);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(421, 389);
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            // 
            // timer1
            // 
            this->timer1->Tick += gcnew System::EventHandler(this, &loadingPage::timer1_Tick);
            // 
            // loadingLabel
            // 
            this->loadingLabel->AutoSize = true;
            this->loadingLabel->BackColor = System::Drawing::Color::Transparent;
            this->loadingLabel->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->loadingLabel->ForeColor = System::Drawing::Color::White;
            this->loadingLabel->Location = System::Drawing::Point(810, 845);
            this->loadingLabel->Name = L"loadingLabel";
            this->loadingLabel->Size = System::Drawing::Size(0, 27);
            this->loadingLabel->TabIndex = 0;
            // 
            // typingTimer
            // 
            this->typingTimer->Tick += gcnew System::EventHandler(this, &loadingPage::typingTimer_Tick);
            // 
            // loadingPage
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::DeepSkyBlue;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(1904, 1041);
            this->Controls->Add(this->loadingLabel);
            this->Controls->Add(this->pictureBox1);
            this->Name = L"loadingPage";
            this->Text = L"SECP";
            this->Load += gcnew System::EventHandler(this, &loadingPage::loadingPage_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void loadingPage_Load(System::Object^ sender, System::EventArgs^ e) {
            this->timer1->Start(); // Start the progress bar timer
            this->typingTimer->Start(); // Start typing effect for the loading label
        }

        System::Void typingTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
            if (textIndex < loadingText->Length) {
                this->loadingLabel->Text += loadingText[textIndex];
                textIndex++;
            }
            else {
                this->typingTimer->Stop(); // Stop the typing timer once the text is fully written
            }
        }

        System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
            progressCount += 100; // Increment the progress count by 100ms

            if (progressCount >= 3500) { // Check if 3 seconds have passed
                timer1->Stop(); // Stop the timer once 3 seconds are complete
                this->Hide(); // Hide the current form

                // Open Signupform when loading completes
                Signupform^ sf = gcnew Signupform();
                sf->ShowDialog(); // Show the next form
                this->Close(); // Close the loading page
            }
        }
    };
}
