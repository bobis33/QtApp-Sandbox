#pragma once

#include <string>
#include <vector>
#include <utility>

#include <QPushButton>
#include <QWidget>
#include <QStackedWidget>

namespace qta {

    class IPage {
    
        public:

            virtual ~IPage() = default;

            virtual void setWidget(QWidget *widget) = 0;
            virtual void setLayout(QVBoxLayout *layout) = 0;

            virtual void addButton(QPushButton *button, const std::string& name) = 0;

            [[nodiscard]] virtual const std::string& getTitle() const = 0;
            [[nodiscard]] virtual QWidget* getWidget() const = 0;
            [[nodiscard]] virtual QVBoxLayout *getLayout() const = 0;

            [[nodiscard]] virtual const std::vector<std::pair<QPushButton *, std::string>>& getButtons() const = 0;
            [[nodiscard]] virtual QPushButton* getButton(const std::string& name) const = 0;

            virtual void deleteResources() = 0;

    }; // class IPage

} // namespace qta
