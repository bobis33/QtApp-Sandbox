#pragma once

#include "QtApp/Abstraction/IPage.hpp"
#include "QtApp/Constant.hpp"

namespace qta {

    class APage : public QWidget, public IPage {

    public:

        explicit APage(std::string title = DEFAULT_PAGE_NAME.data(), QStackedWidget *stackedWidget = nullptr) : QWidget(stackedWidget), m_title(std::move(title)) {}
        virtual ~APage() override = default;

        void setWidget(QWidget *widget) override { m_widget = widget; }
        void setLayout(QVBoxLayout *layout) override { m_layout = layout; }

        void addButton(QPushButton *button, const std::string& name) override { m_buttons.push_back(std::make_pair(button, name)); }

        [[nodiscard]] const std::string& getTitle() const override { return m_title; }
        [[nodiscard]] QWidget* getWidget() const override { return m_widget; }
        [[nodiscard]] QVBoxLayout *getLayout() const override { return m_layout; }

        [[nodiscard]] const std::vector<std::pair<QPushButton *, std::string>>& getButtons() const override { return m_buttons; }
        [[nodiscard]] QPushButton* getButton(const std::string& name) const override {
            for (const auto& button : m_buttons) {
                if (button.second == name) {
                    return button.first;
                }
            }
            return nullptr;
        }

        void deleteResources() override {
            for (const auto &button: m_buttons) {
                delete button.first;
            }
            delete m_layout;
            delete m_widget;
        }

    private:
        std::vector<std::pair<QPushButton *, std::string>> m_buttons;
        std::string m_title;
        QWidget *m_widget;
        QVBoxLayout *m_layout;
        
    }; // class APage

} // namespace qta
