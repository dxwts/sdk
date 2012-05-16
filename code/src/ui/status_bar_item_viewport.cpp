#include "onyx/ui/status_bar_item_viewport.h"

namespace ui
{

static QRect s_bounding;

StatusBarItemViewport::StatusBarItemViewport(QWidget *parent)
    : StatusBarItem(VIEWPORT, parent)
{
    setFixedWidth(30);
}

StatusBarItemViewport::~StatusBarItemViewport(void)
{
}

void StatusBarItemViewport::setViewport(const QRect & parent,
                                        const QRect & child)
{
    parent_ = parent;
    child_ = child;
    s_bounding = parent | child;

    const int w = static_cast<double>(width() - 2);
    const int h = static_cast<double>(height() - 2);
    double scale = std::min(w / static_cast<double>(s_bounding.width()),
                            h / static_cast<double>(s_bounding.height()));

    int left = (w - s_bounding.width() * scale) / 2 + 1;
    int top = (h - s_bounding.height() * scale) / 2 + 1;

    QRect r = QRect(left, top, s_bounding.width() * scale, s_bounding.height() * scale);
    parent_ = QRect(left + (parent_.left() - s_bounding.left()) * scale,
                    top + (parent_.top() - s_bounding.top()) * scale,
                    parent_.width() * scale,
                    parent_.height() * scale);
    child_ = QRect(left + (child_.left() - s_bounding.left()) * scale,
                    top + (child_.top() - s_bounding.top()) * scale,
                    child_.width() * scale,
                    child_.height() * scale);
    s_bounding = r;
    update();
}

void StatusBarItemViewport::paintEvent(QPaintEvent *pe)
{
    QPainter painter(this);
    painter.fillRect(parent_, QBrush(QColor(100, 100, 100, 200)));
    painter.fillRect(child_, QBrush(QColor(255, 255, 255, 200)));
    painter.setPen(Qt::white);
    painter.drawRect(s_bounding.adjusted(-1, -1, 0, -1));

}

}
