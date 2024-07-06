#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>


namespace qta {

    class Window : public QMainWindow {

        public:

            explicit Window(QWidget *parent = nullptr);
            ~Window() override;

        private:

            QWidget *m_centralWidget;
            QVBoxLayout *m_layout;
            QPushButton *m_button;

    }; // class Window

} // namespace qta
