#include <QApplication>

#include "QtApp/Constant.hpp"
#include "QtApp/Tools.hpp"
#include "QtApp/Window.hpp"

qta::Window::Window(const int width, const int height) : QMainWindow(nullptr), m_centralWidget(new QWidget(this)), m_stackedWidget(new QStackedWidget(m_centralWidget)), m_configPanel(new ConfigPanel(this)), m_mainPage(new MainPage()), m_musicPlayerPage(new MusicPlayerPage()), m_layout(new QVBoxLayout(m_centralWidget))
{
    resize(width, height);
    qApp->setApplicationName(WINDOW_TITLE.data());
    qGuiApp->setApplicationDisplayName(qApp->applicationName());

    setWindowTitle(m_mainPage->getTitle().data());

    qApp->setStyleSheet(qta::Tools::getStyleSheet(":/style/dark_theme.qss"));
    qApp->setWindowIcon(QIcon(":/assets/icons/qt.png"));

    m_layout->addWidget(m_configPanel);

    m_stackedWidget->addWidget(m_mainPage->getWidget());
    m_stackedWidget->addWidget(m_musicPlayerPage->getWidget());

    m_layout->addWidget(m_stackedWidget);
    m_centralWidget->setLayout(m_layout);

    setCentralWidget(m_centralWidget);

    handleEvents();
}

qta::Window::~Window()
{
    m_mainPage->deleteResources();
    m_musicPlayerPage->deleteResources();
    m_configPanel->deleteResources();
    delete m_layout;
    delete m_configPanel;
    delete m_mainPage;
    delete m_musicPlayerPage;
    delete m_stackedWidget;
    delete m_centralWidget;
}

void qta::Window::handleEvents()
{
    connect(m_mainPage->getButton("main"), &QPushButton::clicked, [this] {
        m_stackedWidget->setCurrentWidget(m_musicPlayerPage->getWidget());
        setWindowTitle(m_musicPlayerPage->getTitle().data());
    });
    connect(m_musicPlayerPage->getButton("main"), &QPushButton::clicked, [this] {
        m_stackedWidget->setCurrentWidget(m_mainPage->getWidget());
        setWindowTitle(m_mainPage->getTitle().data());
    });

}
