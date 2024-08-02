#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <windows.h>
#include <io.h>
#include <winuser.h>
#include <msclr/marshal_cppstd.h>
#include "MyForm23.h"

namespace docScannerGUI {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace std;
    using namespace cv;

    public ref class MyForm22 : public System::Windows::Forms::Form
    {
    public:
        MyForm22(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm22()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::PictureBox^ pictureBox1;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(410, 52);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(245, 37);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Use this image?";
            // 
            // button1
            // 
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(345, 415);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(197, 110);
            this->button1->TabIndex = 2;
            this->button1->Text = L"Keep";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm22::button1_Click);
            // 
            // button2
            // 
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(629, 415);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(197, 110);
            this->button2->TabIndex = 3;
            this->button2->Text = L"Retake";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm22::button2_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(426, 133);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(317, 251);
            this->pictureBox1->TabIndex = 4;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm22::pictureBox1_Click);
            this->pictureBox1->Image = System::Drawing::Image::FromFile(L"./input.jpg");
            // 
            // MyForm22
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1144, 643);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label1);
            this->Name = L"MyForm22";
            this->Text = L"MyForm22";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        MyForm23^ Mf23 = gcnew MyForm23();
        Mf23->ShowDialog();
    }
    private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

    }
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    //LAUNCH FILE EXPLORER WHEN CLICK RETAKE
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        {
            // Hide the current form (child window) instead of closing it
            this->Close();
            OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
            openFileDialog1->InitialDirectory = "c:\\";
            openFileDialog1->Filter = "Image Files|*.bmp;*.jpg;*.jpeg;*.png|All Files|*.*";
            openFileDialog1->FilterIndex = 1;
            openFileDialog1->RestoreDirectory = true;

            if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                System::String^ filePath = openFileDialog1->FileName;

                // Copy the selected file to input.jpg
                System::String^ destinationPath = "input.jpg";
                System::IO::File::Copy(filePath, destinationPath, true);

                std::string filePathStr = msclr::interop::marshal_as<std::string>(filePath);
                std::cout << "Selected file path: " << filePathStr << std::endl;

                cv::Mat img = cv::imread(filePathStr, cv::IMREAD_COLOR);
                if (img.empty()) {
                    std::cerr << "ERROR! Unable to load image\n";
                    return;
                }

                MyForm22^ Mf22 = gcnew MyForm22();
                Mf22->ShowDialog();
                cv::imshow("Loaded Image", img);
                cv::waitKey(0);
                cv::destroyWindow("Loaded Image");
            }
        }
    }
}


    };
}
