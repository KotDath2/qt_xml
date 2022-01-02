#include "treeitem.h"

TreeItem::TreeItem(const QVector<QVariant> &data, TreeItem *parent)
    : itemData(data), itemParent(parent) {

}

TreeItem::~TreeItem() {
    for (auto node : itemChildren) {
        itemParent = nullptr;
        delete node;
    }
}

TreeItem* TreeItem::child(int row) {
    if (row < 0 || row >= itemChildren.size()) {
        return nullptr;
    }

    return itemChildren.at(row);
}

void TreeItem::appendChild(TreeItem *item) {
    itemChildren.append(item);
}

int TreeItem::rowCount() const {
    return itemChildren.size();
}

int TreeItem::columnCount() const {
    return itemData.size();
}

QVariant TreeItem::data(int column) const {
    if (column < 0 || column >= itemData.size())
            return QVariant();
        return itemData.at(column);
}

TreeItem* TreeItem::parent() const {
    return itemParent;
}

int TreeItem::rowInParent() const {
    if (itemParent) {
        return itemParent->itemChildren.indexOf(const_cast<TreeItem*>(this));
    }
    return 0;
}

void TreeItem::removeChild() {
    itemChildren.pop_back();
}
