#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 알파벳 및 숫자 버튼 클릭 처리
    void ABtnClick();
    void BBtnClick();
    void CBtnClick();
    void DBtnClick();
    void EBtnClick();
    void FBtnClick();
    void GBtnClick();
    void HBtnClick();
    void IBtnClick();
    void JBtnClick();
    void KBtnClick();
    void LBtnClick();
    void MBtnClick();
    void NBtnClick();
    void OBtnClick();
    void PBtnClick();
    void QBtnClick();
    void RBtnClick();
    void SBtnClick();
    void TBtnClick();
    void UBtnClick();
    void VBtnClick();
    void WBtnClick();
    void XBtnClick();
    void YBtnClick();
    void ZBtnClick();

    // 숫자 버튼 클릭 처리
    void oneBtnClick();
    void twoBtnClick();
    void threeBtnClick();
    void fourBtnClick();
    void fiveBtnClick();
    void sixBtnClick();
    void sevenBtnClick();
    void eightBtnClick();
    void nineBtnClick();
    void zeroBtnClick();

    // 기능 버튼 클릭 처리
    void shiftBtn1Click();
    void shiftBtn2Click();
    void capsBtnClick();
    void clearBtnClick();
    void copyBtnClick();
    void spaceBtnClick();      // 스페이스바 클릭 처리
    void backspaceBtnClick();  // 백스페이스 클릭 처리

    // void enterClick();

private:
    Ui::MainWindow *ui;
    bool shiftPress = false; // Shift 상태 변수
    bool capsPress = false;  // Caps 상태 변수

    // 텍스트 입력 처리
    void checkShiftCapsClick(const QString &text);
};

#endif // MAINWINDOW_H
