class outOfBound
{
};

template <class elemType>
class linkList;

template <class elemType>
class node
{
  friend class linkList<elemType>;

private:
  elemType data;
  node *next;

public:
  node(const elemType &x, node *n = NULL)
  {
    data = x;
    next = n;
  }
  node() : next(NULL) {};
};

template <class elemType>
class linkList
{
private:
  node<elemType> *head;

public:
  linkList();
  bool isEmpty() const;
  bool isFull() const { return false; };
  int length() const;
  elemType get(int i) const;
  void insert(int i, const elemType &e);
  void remove(int i, elemType &e);
  int find(const elemType &e) const;
  void reverse() const;
  void clear();
  ~linkList();
};
