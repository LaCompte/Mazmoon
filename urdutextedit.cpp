#include "urdutextedit.h"
#include <QKeyEvent>
#include <QTextCursor>
#include <QDebug>

UrduTextEdit::UrduTextEdit(QWidget *parent)
    : QTextEdit(parent)
{
    setupEditor();
}

void UrduTextEdit::setupEditor()
{
    setLayoutDirection(Qt::RightToLeft);
    setAlignment(Qt::AlignRight);

    QFont font;
    font.setFamily("Noto Nastaliq Urdu");
    font.setPointSize(12);
    setFont(font);

    // Add cursor tracking
    connect(this, &QTextEdit::cursorPositionChanged,
            this, &UrduTextEdit::onCursorPositionChanged);
}

void UrduTextEdit::onCursorPositionChanged()
{
    QTextCursor cursor = textCursor();
    qDebug() << "Cursor position changed to:" << cursor.position() << "Block:" << cursor.blockNumber();
}

void UrduTextEdit::keyPressEvent(QKeyEvent *event)
{
    // Log what's being typed for debugging
    qDebug() << "Key pressed:" << event->text() << "Key:" << event->key();

    // Let Qt handle the input naturally
    QTextEdit::keyPressEvent(event);

    // Add any post-processing if needed
    handleUrduTextInput(event->text());
}

void UrduTextEdit::handleUrduTextInput(const QString &text)
{
    qDebug() << "Processing Urdu text:" << text;

    // Force RTL alignment after any text input
    if (!text.isEmpty() && text != "\b" && text != "\r") {
        QTextCursor cursor = textCursor();
        QTextBlockFormat blockFormat = cursor.blockFormat();
        blockFormat.setLayoutDirection(Qt::RightToLeft);
        blockFormat.setAlignment(Qt::AlignRight);
        cursor.mergeBlockFormat(blockFormat);
    }
}
