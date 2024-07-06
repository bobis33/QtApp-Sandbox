#pragma once

#include <vector>

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QToolButton>

#include "QtApp/Constant.hpp"
#include "QtApp/Page/MainPage.hpp"
#include "QtApp/Page/MusicPlayerPage.hpp"
#include "QtApp/ConfigPanel.hpp"

namespace qta {

    class Window : public QMainWindow {

        public:

            explicit Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
            ~Window() override;

            void handleEvents();

        private:

            QWidget *m_centralWidget;
            QStackedWidget *m_stackedWidget;
            ConfigPanel *m_configPanel;
            MainPage *m_mainPage;
            MusicPlayerPage *m_musicPlayerPage;
            QVBoxLayout *m_layout;

    }; // class Window

} // namespace qta
