#include <QMenu>
#include <QToolButton>
#include <QAction>
#include <QApplication>

#include "QtApp/ConfigPanel.hpp"
#include "QtApp/Tools.hpp"

qta::ConfigPanel::ConfigPanel(QWidget *parent) : QWidget(parent), m_configButton(new QToolButton(this)), m_configMenu(new QMenu("Settings", this)), m_layout(new QVBoxLayout(this))
{
    m_configButton->setPopupMode(QToolButton::InstantPopup);
    m_configButton->setIcon(QIcon(":/assets/icons/settings.png"));
    m_configButton->setToolTip("Settings");
    m_configButton->setFixedSize(24, 24);

    QMenu *themeMenu = new QMenu("Choose Theme", m_configMenu);
    QAction *themeAction = new QAction("Dark Theme", themeMenu);
    themeMenu->addAction(themeAction);
    connect(themeAction, &QAction::triggered, [] {
        qApp->setStyleSheet(qta::Tools::getStyleSheet(":/style/dark_theme.qss"));
    });
    themeAction = new QAction("Light Theme", themeMenu);
    themeMenu->addAction(themeAction);
    connect(themeAction, &QAction::triggered, [] {
        qApp->setStyleSheet(qta::Tools::getStyleSheet(":/style/light_theme.qss"));
    });

    m_configMenu->addMenu(themeMenu);

    m_configButton->setMenu(m_configMenu);

    m_layout->addWidget(m_configButton);
    m_layout->setAlignment(m_configButton, Qt::AlignTop | Qt::AlignRight);

    setLayout(m_layout);
}

void qta::ConfigPanel::deleteResources()
{
    delete m_layout;
    for (QAction *action : m_configMenu->actions())
    {
        delete action;
    }
    delete m_configButton;
    delete m_configMenu;
}
