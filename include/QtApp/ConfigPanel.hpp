#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

namespace qta {

    class ConfigPanel : public QWidget {

        public:

            explicit ConfigPanel(QWidget *parent = nullptr);
            ~ConfigPanel() override = default;

            void deleteResources();

        private:

            QToolButton *m_configButton;
            QMenu *m_configMenu;
            QVBoxLayout *m_layout;

    }; // class ConfigPanel

} // namespace qta
