#include "Life.h"

//void ChangeFieldStatus::randomFieldFill() {
//
//}

void ChangeField::pulseFieldFill(Field &field) {
    const size_t X = 0;
    const size_t Y = 0;

    vector<Cell> cells;
    for (size_t j = 0; j < 2; j++) {
        for (size_t i = 0; i < 3; i++) {
            Cell cell(i + 2 + X, Y + 5 * j);
            field.cellsList->addCell(cell, field.getRows(), field.getColums(), 0);
        }
        for (size_t i = 0; i < 3; i++) {
            Cell cell(i + 8 + X, Y + 5 * j);
            field.cellsList->addCell(cell, field.getRows(), field.getColums(), 0);
        }
    }
}

void Field::recursionDraw(BlockOfCells *node, set<Cell>::iterator it, size_t &i, size_t &j) {
    if (node->left != nullptr) {
        recursionDraw(node->left, it, i, j);
    }
    if (node->right != nullptr) {
        recursionDraw(node->right, it, i, j);
    }

    it = node->cellsTree->begin();
    for (; i < rows; i++) {
        for (; j < columns; j++) {
            if (it == node->cellsTree->end()) {
                return;
            }
            if ((*it).getX() == i && (*it).getY() == j) {
                cout << "1";
                it++;
            } else {
                cout << "0";
            }
        }
        j = 0;
        cout << "\n";
    }
}

void Field::drawField() {
//    for (size_t i = 0; i < field.getRows(); i++) {
//        for (size_t j = 0; j < field.getColums(); j++) {
//            field.cellsList->cellIsExist(i, j);
//        }
//        cout << "\n" << endl;
//    }
    size_t i = 0, j = 0;
    set<Cell>::iterator it;
    recursionDraw(this->cellsList, it, i, j);
    for (; i < rows; i++) {
        for (; j < columns; j++) {
            cout << "0";
        }
        j = 0;
        cout << "\n";
    }
}

void Life::runningStandartGame() {
    this->field.drawField();
}

void Life::runningOfflineGame() {

}
