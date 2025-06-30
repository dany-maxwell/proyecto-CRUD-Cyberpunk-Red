#ifndef CHARACTERSHEETMANAGER_H
#define CHARACTERSHEETMANAGER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CharacterSheetManager;
}
QT_END_NAMESPACE

class CharacterSheetManager : public QMainWindow
{
    Q_OBJECT

public:
    CharacterSheetManager(QWidget *parent = nullptr);
    ~CharacterSheetManager();

private:
    Ui::CharacterSheetManager *ui;
};
#endif // CHARACTERSHEETMANAGER_H
