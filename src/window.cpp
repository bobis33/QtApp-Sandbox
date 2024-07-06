#include "QtApp/Constant.hpp"
#include "QtApp/Window.hpp"
#include "QtApp/Tools.hpp"

qta::Window::Window(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(DEFAULT_TITLE.data());
    resize(DEFAULT_WIDTH, DEFAULT_HEIGHT);

    m_centralWidget = new QWidget(this);
    setCentralWidget(m_centralWidget);

    m_layout = new QVBoxLayout(m_centralWidget);
    m_button = new QPushButton("Hello, Qt!", m_centralWidget);
    m_button->setStyleSheet(qta::Tools::getStyleSheet("style/style.qss"));
    m_layout->addStretch(1);
    m_layout->addWidget(m_button);
}

qta::Window::~Window()
{
    delete m_button;
    delete m_layout;
    delete m_centralWidget;
}
