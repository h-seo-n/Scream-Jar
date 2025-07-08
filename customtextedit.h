#ifndef CUSTOMTEXTEDIT_H
#define CUSTOMTEXTEDIT_H

#include <QTextEdit>
#include <QKeyEvent>
#include <QPushButton>

class CustomTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit CustomTextEdit(QWidget *parent=nullptr, QPushButton *screamButton = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QPushButton *enterButton;
};

#endif // CUSTOMTEXTEDIT_H
