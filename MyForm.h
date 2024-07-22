#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2\imgcodecs.hpp>   
#include <iostream>
#include <windows.h>
namespace docScannerGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace cv;

	Mat src = imread("C:/Users/Amir/source/repos/docScannerGUI/docScannerGUI/IMG_9730.jpg", 0);
	int ct = 0;
	char screenshot;
	char filename[100]; // For filename
	int  c = 1; // For filename
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
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		VideoCapture cap(0);
		Mat edges;
		while (true)
		{
			Mat frame;
			cap >> frame;
			for (;;)
			{
				// wait for a new frame from camera and store it into 'frame'
				cap.read(frame);

				if (frame.empty()) {
					cerr << "ERROR! blank frame grabbed\n";
					break;
				}



				// show live and wait for a key with timeout long enough to show images
				imshow("CAMERA 1", frame);  // Window name
				imshow("CAMERA 1", frame);  // Window name


				screenshot = cv::waitKey(30);


				if (screenshot == ' ') {

					sprintf_s(filename, "./Frame_%d.jpg", c); // select your folder - filename is "Frame_n"
					cv::waitKey(45);

					imshow("CAMERA 1", frame);
					imwrite(filename, frame);
					cout << "Frame_" << c << endl;
					c++;
				}

				if (screenshot == 'a') {
					cout << "Terminating..." << endl;
					Sleep(5000); //find way to close cam window without closing app itself
					break;
				}
			}
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	system("explorer");

}
};
}
