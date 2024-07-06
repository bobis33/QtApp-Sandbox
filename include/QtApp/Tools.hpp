#pragma once

#include <iostream>

#include <QString>
#include <QFile>
#include <QTextStream>

namespace qta {

    class Tools {

        public:

            static QString getStyleSheet(const QString& filePath) {
                QFile file(filePath);
                if (!file.open(QIODevice::ReadOnly)) {
                    std::cerr << "Failed to open style: " << file.fileName().toStdString() << '\n';
                    return QString{};
                }
                QString styleSheet = QTextStream(&file).readAll();
                file.close();
                return styleSheet;
            }

    }; // class Tools

} // namespace qta
