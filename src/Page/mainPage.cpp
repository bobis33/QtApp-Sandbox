#include <QBoxLayout>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineQuick/QtWebEngineQuick>

#include "QtApp/Page/MainPage.hpp"
#include "QtApp/Tools.hpp"

qta::MainPage::MainPage(const std::string& title) : APage(title)
{
    APage::setWidget(new QWidget(this));
    APage::setLayout(new QVBoxLayout(APage::getWidget()));

    auto *button = new QPushButton("Go to Page 2", APage::getWidget());
    APage::addButton(button, "main");

    QHBoxLayout *webLayout = new QHBoxLayout(APage::getLayout()->widget());

    auto *webEngineView1 = new QWebEngineView(APage::getWidget());
    webEngineView1->load(QUrl("https://www.youtube.com/"));
    webEngineView1->setFixedSize(800, 600);

    auto *webEngineView2 = new QWebEngineView(APage::getWidget());
    webEngineView2->load(QUrl("https://www.chatgpt.com/"));
    webEngineView2->setFixedSize(800, 600);

    webLayout->addWidget(webEngineView1);
    webLayout->addWidget(webEngineView2);
    APage::getLayout()->addLayout(webLayout);
    APage::getLayout()->addStretch(1);
    APage::getLayout()->addWidget(button);
}
