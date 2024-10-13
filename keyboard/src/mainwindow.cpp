#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 버튼 클릭 시그널과 슬롯을 연결
    connect(ui->A_btn, &QPushButton::clicked, this, &MainWindow::ABtnClick);
    connect(ui->B_btn, &QPushButton::clicked, this, &MainWindow::BBtnClick);
    connect(ui->C_btn, &QPushButton::clicked, this, &MainWindow::CBtnClick);
    connect(ui->D_btn, &QPushButton::clicked, this, &MainWindow::DBtnClick);
    connect(ui->E_btn, &QPushButton::clicked, this, &MainWindow::EBtnClick);
    connect(ui->F_btn, &QPushButton::clicked, this, &MainWindow::FBtnClick);
    connect(ui->G_btn, &QPushButton::clicked, this, &MainWindow::GBtnClick);
    connect(ui->H_btn, &QPushButton::clicked, this, &MainWindow::HBtnClick);
    connect(ui->I_btn, &QPushButton::clicked, this, &MainWindow::IBtnClick);
    connect(ui->J_btn, &QPushButton::clicked, this, &MainWindow::JBtnClick);
    connect(ui->K_btn, &QPushButton::clicked, this, &MainWindow::KBtnClick);
    connect(ui->L_btn, &QPushButton::clicked, this, &MainWindow::LBtnClick);
    connect(ui->M_btn, &QPushButton::clicked, this, &MainWindow::MBtnClick);
    connect(ui->N_btn, &QPushButton::clicked, this, &MainWindow::NBtnClick);
    connect(ui->O_btn, &QPushButton::clicked, this, &MainWindow::OBtnClick);
    connect(ui->P_btn, &QPushButton::clicked, this, &MainWindow::PBtnClick);
    connect(ui->Q_btn, &QPushButton::clicked, this, &MainWindow::QBtnClick);
    connect(ui->R_btn, &QPushButton::clicked, this, &MainWindow::RBtnClick);
    connect(ui->S_btn, &QPushButton::clicked, this, &MainWindow::SBtnClick);
    connect(ui->T_btn, &QPushButton::clicked, this, &MainWindow::TBtnClick);
    connect(ui->U_btn, &QPushButton::clicked, this, &MainWindow::UBtnClick);
    connect(ui->V_btn, &QPushButton::clicked, this, &MainWindow::VBtnClick);
    connect(ui->W_btn, &QPushButton::clicked, this, &MainWindow::WBtnClick);
    connect(ui->X_btn, &QPushButton::clicked, this, &MainWindow::XBtnClick);
    connect(ui->Y_btn, &QPushButton::clicked, this, &MainWindow::YBtnClick);
    connect(ui->Z_btn, &QPushButton::clicked, this, &MainWindow::ZBtnClick);

    // 숫자 버튼
    connect(ui->one_btn, &QPushButton::clicked, this, &MainWindow::oneBtnClick);
    connect(ui->two_btn, &QPushButton::clicked, this, &MainWindow::twoBtnClick);
    connect(ui->three_btn, &QPushButton::clicked, this, &MainWindow::threeBtnClick);
    connect(ui->four_btn, &QPushButton::clicked, this, &MainWindow::fourBtnClick);
    connect(ui->five_btn, &QPushButton::clicked, this, &MainWindow::fiveBtnClick);
    connect(ui->six_btn, &QPushButton::clicked, this, &MainWindow::sixBtnClick);
    connect(ui->seven_btn, &QPushButton::clicked, this, &MainWindow::sevenBtnClick);
    connect(ui->eight_btn, &QPushButton::clicked, this, &MainWindow::eightBtnClick);
    connect(ui->nine_btn, &QPushButton::clicked, this, &MainWindow::nineBtnClick);
    connect(ui->zero_btn, &QPushButton::clicked, this, &MainWindow::zeroBtnClick);

    // Shift, Caps, Clear, Space, Backspace 버튼 연결
    connect(ui->Shift_btn1, &QPushButton::clicked, this, &MainWindow::shiftBtn1Click);
    connect(ui->Shift_btn2, &QPushButton::clicked, this, &MainWindow::shiftBtn2Click);
    connect(ui->Caps_btn, &QPushButton::clicked, this, &MainWindow::capsBtnClick);
    connect(ui->clear_btn, &QPushButton::clicked, this, &MainWindow::clearBtnClick);
    connect(ui->copy_btn, &QPushButton::clicked, this, &MainWindow::copyBtnClick);
    connect(ui->space_btn, &QPushButton::clicked, this, &MainWindow::spaceBtnClick); // 스페이스바 버튼
    connect(ui->backspace_btn, &QPushButton::clicked, this, &MainWindow::backspaceBtnClick); // 백스페이스 버튼
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 알파벳 및 숫자 버튼 클릭 처리
// 특수 문자와 숫자를 매핑
const QString specialChars[] = {
    "!", "@", "#", "$", "%", "^", "&", "*", "(", ")",
    "-", "_", "=", "+", "[", "]", "{", "}", ";", "'",
    ",", ".", "/", "<", ">", "?"
};

// 기존 코드의 checkShiftCapsClick 함수 수정
void MainWindow::checkShiftCapsClick(const QString &text)
{
    QString letter = text;

    if (shiftPress || capsPress) {
        letter = letter.toUpper();
    } else {
        letter = letter.toLower();
    }

    // DisplayField에 텍스트 추가
    ui->DisplayField->insert(letter);
    ui->DisplayField->setCursorPosition(ui->DisplayField->text().length());
    ui->DisplayField->setFocus();

    // Shift는 한번만 적용되므로 다시 false로 변경
    if (shiftPress) {
        shiftPress = false;
    }
}

// 숫자 버튼 클릭 처리 수정
void MainWindow::oneBtnClick() {
    ui->DisplayField->insert(capsPress ? specialChars[1] : "1"); // 1 -> !
}
void MainWindow::twoBtnClick() {
    ui->DisplayField->insert(capsPress ? specialChars[2] : "2"); // 2 -> @
}
void MainWindow::threeBtnClick() {
    ui->DisplayField->insert(capsPress ? specialChars[3] : "3"); // 3 -> #
}
void MainWindow::fourBtnClick() {
    ui->DisplayField->insert(capsPress ? specialChars[4] : "4"); // 4 -> $
}
void MainWindow::fiveBtnClick() {
    ui->DisplayField->insert(capsPress ? specialChars[5] : "5"); // 5 -> %
}
void MainWindow::sixBtnClick() {
    ui->DisplayField->insert(capsPress ? specialChars[6] : "6"); // 6 -> ^
}
void MainWindow::sevenBtnClick() {
    ui->DisplayField->insert(capsPress ? specialChars[7] : "7"); // 7 -> &
}
void MainWindow::eightBtnClick() {
    ui->DisplayField->insert(capsPress ? specialChars[8] : "8"); // 8 -> *
}
void MainWindow::nineBtnClick() {
    ui->DisplayField->insert(capsPress ? specialChars[9] : "9"); // 9 -> (
}
void MainWindow::zeroBtnClick() {
    ui->DisplayField->insert(capsPress ? specialChars[10] : "0"); // 0 -> )
}

// 나머지 코드 그대로 유지


void MainWindow::shiftBtn1Click() { shiftPress = true; }
void MainWindow::shiftBtn2Click() { shiftPress = true; }
void MainWindow::capsBtnClick() { capsPress = !capsPress; }
void MainWindow::clearBtnClick() { ui->DisplayField->clear(); }
void MainWindow::copyBtnClick() { QString text = ui->DisplayField->text(); }

// 스페이스바 버튼 클릭 처리
void MainWindow::spaceBtnClick() {
    ui->DisplayField->insert(" "); // 공백 추가
    ui->DisplayField->setCursorPosition(ui->DisplayField->text().length()); // 커서를 맨 끝으로 이동
}

// 백스페이스 버튼 클릭 처리
void MainWindow::backspaceBtnClick() {
    ui->DisplayField->backspace(); // 마지막 글자 삭제
}

// 숫자 버튼 클릭 처리
// void MainWindow::oneBtnClick() { ui->DisplayField->insert("1"); }
// void MainWindow::twoBtnClick() { ui->DisplayField->insert("2"); }
// void MainWindow::threeBtnClick() { ui->DisplayField->insert("3"); }
// void MainWindow::fourBtnClick() { ui->DisplayField->insert("4"); }
// void MainWindow::fiveBtnClick() { ui->DisplayField->insert("5"); }
// void MainWindow::sixBtnClick() { ui->DisplayField->insert("6"); }
// void MainWindow::sevenBtnClick() { ui->DisplayField->insert("7"); }
// void MainWindow::eightBtnClick() { ui->DisplayField->insert("8"); }
// void MainWindow::nineBtnClick() { ui->DisplayField->insert("9"); }
// void MainWindow::zeroBtnClick() { ui->DisplayField->insert("0"); }

// 알파벳 버튼 클릭 처리
void MainWindow::ABtnClick() { checkShiftCapsClick("A"); }
void MainWindow::BBtnClick() { checkShiftCapsClick("B"); }
void MainWindow::CBtnClick() { checkShiftCapsClick("C"); }
void MainWindow::DBtnClick() { checkShiftCapsClick("D"); }
void MainWindow::EBtnClick() { checkShiftCapsClick("E"); }
void MainWindow::FBtnClick() { checkShiftCapsClick("F"); }
void MainWindow::GBtnClick() { checkShiftCapsClick("G"); }
void MainWindow::HBtnClick() { checkShiftCapsClick("H"); }
void MainWindow::IBtnClick() { checkShiftCapsClick("I"); }
void MainWindow::JBtnClick() { checkShiftCapsClick("J"); }
void MainWindow::KBtnClick() { checkShiftCapsClick("K"); }
void MainWindow::LBtnClick() { checkShiftCapsClick("L"); }
void MainWindow::MBtnClick() { checkShiftCapsClick("M"); }
void MainWindow::NBtnClick() { checkShiftCapsClick("N"); }
void MainWindow::OBtnClick() { checkShiftCapsClick("O"); }
void MainWindow::PBtnClick() { checkShiftCapsClick("P"); }
void MainWindow::QBtnClick() { checkShiftCapsClick("Q"); }
void MainWindow::RBtnClick() { checkShiftCapsClick("R"); }
void MainWindow::SBtnClick() { checkShiftCapsClick("S"); }
void MainWindow::TBtnClick() { checkShiftCapsClick("T"); }
void MainWindow::UBtnClick() { checkShiftCapsClick("U"); }
void MainWindow::VBtnClick() { checkShiftCapsClick("V"); }
void MainWindow::WBtnClick() { checkShiftCapsClick("W"); }
void MainWindow::XBtnClick() { checkShiftCapsClick("X"); }
void MainWindow::YBtnClick() { checkShiftCapsClick("Y"); }
void MainWindow::ZBtnClick() { checkShiftCapsClick("Z"); }
