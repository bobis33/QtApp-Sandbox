#include <QBoxLayout>

#include "QtApp/Page/MainPage.hpp"
#include "QtApp/Tools.hpp"

qta::MainPage::MainPage(const std::string& title) : APage(title)
{
    APage::setWidget(new QWidget());
    APage::setLayout(new QVBoxLayout(APage::getWidget()));
    auto *button = new QPushButton("Go to Page 2", APage::getWidget());
    APage::addButton(button, "main");
    APage::getLayout()->addStretch(1);
    APage::getLayout()->addWidget(button);
}
