#include "urdutextedit.h"
#include <QKeyEvent>
#include <QTextCursor>

UrduTextEdit::UrduTextEdit(QWidget *parent)
    : QTextEdit(parent)
{
    setupEditor();
}

void UrduTextEdit::setupEditor()
{
    setLayoutDirection(Qt::RightToLeft);
    setAlignment(Qt::AlignRight);

    // Set default font for Urdu
    QFont font;
    font.setFamily("Noto Nastaliq Urdu");
    font.setPointSize(12);
    setFont(font);
}

void UrduTextEdit::keyPressEvent(QKeyEvent *event)
{
    // Basic implementation - will enhance with InPage keyboard mapping later
    QTextEdit::keyPressEvent(event);
}
