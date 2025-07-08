#include "customtextedit.h"

CustomTextEdit::CustomTextEdit(QWidget *parent, QPushButton *screamButton)
    : QTextEdit(parent), enterButton(screamButton){}

void CustomTextEdit::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter){
        if (event->modifiers() & Qt::ShiftModifier) {
            // Shift+Enter : Insert a new line
            QTextEdit::keyPressEvent(event);
        } else {
            // Enter : Trigger the screamButton(scream!)
            if (enterButton) {
                enterButton->click();
            }
            event->accept();
        }
    } else {
        // Default behavior for other keys
        QTextEdit::keyPressEvent(event);
    }
}

