#ifndef URDUTEXTEDIT_H
#define URDUTEXTEDIT_H

#include <QTextEdit>
#include <QKeyEvent>

class UrduTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit UrduTextEdit(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onCursorPositionChanged();

private:
    void setupEditor();
    void handleUrduTextInput(const QString &text);
};

#endif // URDUTEXTEDIT_H
