#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <msclr/marshal_cppstd.h>

namespace docScannerGUI {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace std;
    using namespace cv;

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
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button1;
    private: System::ComponentModel::IContainer^ components;

    protected:

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(510, 64);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(288, 29);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Amir\'s Document Scanner";
            this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
            // 
            // button1
            // 
            this->button1->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24));
            this->button1->ForeColor = System::Drawing::SystemColors::ButtonFace;
            this->button1->Location = System::Drawing::Point(222, 202);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(296, 190);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Capture Webcam";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // button2
            // 
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24));
            this->button2->ForeColor = System::Drawing::SystemColors::ButtonFace;
            this->button2->Location = System::Drawing::Point(747, 202);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(279, 190);
            this->button2->TabIndex = 2;
            this->button2->Text = L"Upload Image";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1251, 640);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label1);
            this->Name = L"MyForm";
            this->Text = L"Document Scanner";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        // Handle form load event
    }

    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
        // Handle label click event
    }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        VideoCapture cap(0);
        if (!cap.isOpened()) {
            cerr << "ERROR! Unable to open camera\n";
            return;
        }

        Mat frame;
        int c = 0;
        char filename[100];
        int screenshot;
        const std::string windowName = "CAMERA 1";
        namedWindow(windowName.c_str());

        while (true) {
            // wait for a new frame from camera and store it into 'frame'
            cap.read(frame);

            if (frame.empty()) {
                cerr << "ERROR! blank frame grabbed\n";
                break;
            }

            // show live and wait for a key with timeout long enough to show images
            imshow(windowName.c_str(), frame);

            screenshot = cv::waitKey(30);

            if (screenshot == ' ') {
                sprintf_s(filename, sizeof(filename), "./input.jpg"); // select your folder - filename is "Frame_n"
                imwrite(filename, frame);
                Sleep(1000);
                cout << "Screenshot Taken";
                // open new window with screenshot embedded and option to either use image or retake
                

                cv::Mat ss = cv::imread("./input.jpg");

                cv::imshow("Loaded Image", ss);
                cv::waitKey(0);
                cv::destroyWindow("Loaded Image");
            }

            if (screenshot == 27) {
                cout << "Terminating..." << endl;
                destroyWindow(windowName.c_str()); // Close the window without terminating the application
                break;
            }
        }

        // Release the camera
        cap.release();
    }

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
    openFileDialog1->InitialDirectory = "c:\\";
    openFileDialog1->Filter = "Image Files|*.bmp;*.jpg;*.jpeg;*.png|All Files|*.*";
    openFileDialog1->FilterIndex = 1;
    openFileDialog1->RestoreDirectory = true;

    if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        // Get the selected file path
        System::String^ filePath = openFileDialog1->FileName;

        // Convert the file path to std::string
        std::string filePathStr = msclr::interop::marshal_as<std::string>(filePath);

        // Print the file path
        std::cout << "Selected file path: " << filePathStr << std::endl;

        // Load and display the image
        cv::Mat img = cv::imread(filePathStr, cv::IMREAD_COLOR);
        if (img.empty()) {
            std::cerr << "ERROR! Unable to load image\n";
            return;
        }

        // Display the loaded image
        cv::imshow("Loaded Image", img);
        cv::waitKey(0);
        cv::destroyWindow("Loaded Image");
    }
}
    };
}
