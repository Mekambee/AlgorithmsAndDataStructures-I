// Szablon dla węzła drzewa binarnego i drzewa BST.
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cassert>
#include <stack>
#include <cstdlib>
#include <queue>
template <typename T>
struct BSTNode
{
    // the default access mode and default inheritance mode are public
    T value;
    BSTNode *left, *right;
    // BSTNode *parent;   // używane w pewnych zastosowaniach
    //  kostruktor domyślny
    BSTNode() : value(T()), left(nullptr), right(nullptr) {}
    // konstruktor zwykły
    BSTNode(const T &item) : value(item), left(nullptr), right(nullptr) {}
    ~BSTNode() {} // destruktor
};
// Szablon dla przypadkowego drzewa binarnego.
template <typename T>
class RandomBinaryTree
{
    BSTNode<T> *root;

public:
    RandomBinaryTree() : root(nullptr) {} // konstruktor domyślny
    ~RandomBinaryTree() { clear(); }      // trzeba wyczyścić
    bool empty() const { return root == nullptr; }
    T &top()
    {
        assert(root != nullptr);
        return root->value;
    } // podgląd korzenia
    void insert(const T &item) { root = insert(root, item); }
    // void remove(const T& item); // na razie nie usuwamy elementów
    //  Szukając element dostajemy wskaźnik do elementu lub nullptr.
    T *search(const T &item) const
    {
        auto ptr = search(root, item);
        return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }
    T *find_min();
    T *find_max();
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }
    void iter_preorder();
    void iter_inorder();   // trudne
    void iter_postorder(); // trudne
    void bfs();            // przejście poziomami (wszerz)
    void clear()
    {
        clear(root);
        root = nullptr;
    }
    void display() { display(root, 0); }
    // Metody bezpośrednio odwołujące się do node.
    // Mogą działać na poddrzewie.
    void clear(BSTNode<T> *node)
    {
        if (node == nullptr)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
    BSTNode<T> *insert(BSTNode<T> *node, const T &item); // zwraca nowy korzeń
    BSTNode<T> *search(BSTNode<T> *node, const T &item) const;
    void preorder(BSTNode<T> *node);
    void inorder(BSTNode<T> *node);
    void postorder(BSTNode<T> *node);
    void display(BSTNode<T> *node, int level);
    virtual void visit(BSTNode<T> *node)
    {
        assert(node != nullptr);
        std::cout << "visiting " << node->value << std::endl;
    }


    int calc_leafs_rekurencja(BSTNode<T> *node)
    {

        if(node == nullptr){
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            return 1;
        }
        return calc_leafs_rekurencja(node->left) + calc_leafs_rekurencja(node->right);
    }

    int calc_leafs_iteracja()
    {
        if (root == nullptr)
            return 0;
        std::queue<BSTNode<T> *> Q;
        int leafs = 0;
        BSTNode<T> *node = root;
        Q.push(node);
        while (!Q.empty())
        {
            node = Q.front();
            Q.pop();
            if (node->left == nullptr && node->right == nullptr)
            {
                leafs++;
            }
            if (node->left != nullptr)
                Q.push(node->left);
            if (node->right != nullptr)
                Q.push(node->right);
        }
        return leafs;
    }

    void show_leafs_number()
    {
        std::cout << "Funkcja calc_leafs(), (sposób iteracyjny), Liczba liści drzewa binarnego: " << calc_leafs_iteracja() << std::endl;
        std::cout << "Funkcja calc_leafs(), (sposób rekurencyjny), Liczba liści drzewa binarnego: " << calc_leafs_rekurencja(root) << std::endl;

    }
};

template <typename T>
void RandomBinaryTree<T>::display(BSTNode<T> *node, int level)
{
    if (node == nullptr)
        return;
    display(node->right, level + 1);
    std::cout << std::string(3 * level, ' ') << node->value << std::endl;
    display(node->left, level + 1);
}
template <typename T>
BSTNode<T> *RandomBinaryTree<T>::insert(BSTNode<T> *node, const T &item)
{
    if (node == nullptr)
    {
        return new BSTNode<T>(item);
    }
    if (std::rand() % 2)
    { // można lepiej
        node->left = insert(node->left, item);
    }
    else
    {
        node->right = insert(node->right, item);
    }
    return node; // zwraca nowy korzen
}
template <typename T>
BSTNode<T> *RandomBinaryTree<T>::search(BSTNode<T> *node, const T &item) const
{
    if (node == nullptr || node->value == item)
    {
        return node;
    }
    T *ptr;
    ptr = search(node->left, item);
    if (ptr == nullptr)
    {
        ptr = search(node->right, item);
    }
    return ptr;
}

#endif
