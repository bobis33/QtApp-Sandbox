#include <QBoxLayout>

#include "QtApp/Page/MusicPlayerPage.hpp"
#include "QtApp/Tools.hpp"

qta::MusicPlayerPage::MusicPlayerPage(const std::string& title) : APage(title)
{
    APage::setWidget(new QWidget());
    APage::setLayout(new QVBoxLayout(APage::getWidget()));
    auto *button = new QPushButton("Back to page 1", APage::getWidget());
    APage::addButton(button, "main");
    APage::getLayout()->addWidget(button);
    APage::getLayout()->addStretch(1);
}
