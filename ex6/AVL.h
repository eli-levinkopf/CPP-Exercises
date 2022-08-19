//
// Created by rotem on 07/10/2021.
//

#ifndef _AVL_H_
#define _AVL_H_
#include <vector>
#include <stack>
#include "Apartment.h"

class AVL {
 public:
  class Iterator;
  class ConstIterator;
  /**
   * To manage the tree nodes, we use a nested struct. This struct contains the
   * apartment corresponding to the node, the left son and the right son of the
   * node, both of them node type themselves.
   */
  struct node {
	/**
	 * Constructor - It can be expanded
	 * @param data the corresponding apartment object
	 * @param left child
	 * @param right child
	 */
	node (Apartment data);
	node (const node &other);
	~node ();
	node &operator= (const node &other);
	/**
	 *
	 * @return the left child of this node
	 */
	node *get_left () const
	{
	  return left_;
	}
	/**
	 *
	 * @return the right child of this node
	 */
	node *get_right () const
	{
	  return right_;
	}
	/**
   *
   * @return the const reference apartment of this node
   */
	const Apartment &get_data () const
	{
	  return data_;
	}
	/**
	 * @return the height of this node
	 */
	int get_height () const;
	/**
	 * @return the balance factor of this node (left_->height - right_->height)
	 */
	int get_balance_factor () const;
	/**
	 * update the height of this
	 */
	void set_height ();
	/**
	 * Insert new node to to the tree that this is its root
	 * @param new_node reference to node
	 * @return pointer to root
	 */
	node *insert (node &new_node);
	/**
	 * rotate this to right rotate
	 * @return pointer to root
	 */
	node *right_rotate ();
	/**
	 * rotate this to left rotate
	 * @return pointer to root
	 */
	node *left_rotate ();
	/**
	 * Balances the tree
	 * @return pointer to root
	 */
	node *avl_balance ();
	/**
	 * Deletes node with data = apartment from this tree
	 * @param apartment reference to apartment
	 * @return pointer to root
	 */
	node *erase_node (const Apartment &apartment);
	/**
	 * Find the successor of this
	 * @return The apartment of the successor
	 */
	Apartment find_successor_in_sub_tree ();
	Apartment data_;
	node *left_, *right_;
	int height_;
  };

  friend struct node;
  //**************** Constructors ****************//
  /**
   * Constructor. Constructs an empty AVL tree
   */
  AVL ();
  /**
   * Copy constructor
   * @param other reference to AVL
   */
  AVL (const AVL &other);
  /**
   * A constructor that receives a vector of a pairs. Each such pair is an
   * apartment that will inserted to the tree. Insert can be used to insert the
   * apartments a vector of a pairs
   * @param coordinates vector of coordinates
   */
  AVL (std::vector<std::pair<double, double>> coordinates);
  //**************** Destructor ****************//
  ~AVL ();
  //**************** Assignment operator ****************//
  AVL &operator= (const AVL &other);
  /**
   * @return the root node of this tree
   */
  node *get_root () const
  {
	return root_;
  }

  /**
   * The function inserts the new apartment into the tree so that it maintains
   * the legality of the tree.
   * @param apartment reference to an apartment
   */
  void insert (const Apartment &apartment);
  /**
   * The function deletes the apartment from the tree (if it is in that tree)
   * so that it maintains
   * the legality of the tree.
   * @param apartment reference to an apartment
   */
  void erase (const Apartment &apartment);
  /**
   * The class should support forward Iterator. Don't forget to define the
   * Iterator traits and all the actions required to support a forward Iterator
   * The Iterator will move in preorder.
   */

  //****************************************//
  //*************** Iterator ***************//
  //****************************************//
  class Iterator {
	node *root_;
	std::stack<node *> nodes_stack_;
	friend class ConstIterator;
   public:
	//****************************************//
	//*************** typedefs ***************//
	//****************************************//
	typedef node value_type;
	typedef Apartment *pointer;
	typedef Apartment &reference;
	typedef std::forward_iterator_tag iterator_category;
	typedef std::ptrdiff_t difference_type;

	Iterator (node *root);

	//****************************************//
	//*************** operators **************//
	//****************************************//;
	pointer operator-> ();
	reference operator* ();
	Iterator &operator++ ();
	Iterator operator++ (int);
	bool operator== (const Iterator &rhs) const;
	bool operator!= (const Iterator &rhs) const;
	/**
	 * search the apartment in this AVL
	 * @param apartment reference to an apartment
	 * @return Iterator to the node if the apartment in this AVL
	 */
	Iterator bst (Apartment apartment);
	/**
	 * Copy the src stack to dst stack
	 * @param src stack of nodes
	 * @param dst stack of nodes
	 */
	void copy_reverse (std::stack<node *> src, std::stack<node *> dst) const;
  };

  //****************************************//
  //*************** ConstIterator **********//
  //****************************************//
  class ConstIterator {
	node *root_;
	std::stack<node *> nodes_stack_;
   public:
	//****************************************//
	//*************** typedefs ***************//
	//****************************************//
	typedef node value_type;
	typedef const Apartment *pointer;
	typedef const Apartment &reference;
	typedef std::forward_iterator_tag iterator_category;
	typedef std::ptrdiff_t difference_type;

	ConstIterator (node *root);
	ConstIterator (const Iterator &it);

	//****************************************//
	//*************** operators **************//
	//****************************************//
	pointer operator-> ();
	reference operator* ();
	ConstIterator &operator++ ();
	ConstIterator operator++ (int);
	bool operator== (const ConstIterator &rhs) const;
	bool operator!= (const ConstIterator &rhs) const;
	/**
	 * search the apartment in this AVL
	 * @param apartment reference to an apartment
	 * @return Iterator to the node if the apartment in this AVL
	 */
	ConstIterator bst (Apartment apartment);
  };

  using iterator = Iterator;
  using const_iterator = ConstIterator;
  iterator begin ();
  iterator end ();
  const_iterator begin () const;
  const_iterator end () const;
  const_iterator cbegin () const;
  const_iterator cend () const;

  /**
   * The function returns an Iterator to the item that corresponds to the item
   * we were looking for. If there is no such member, returns end ().
   * @param data apartment to search
   * @return Iterator to the item that corresponds to the item
   * we were looking for. If there is no such member, returns end ().
   */
  iterator find (const Apartment &data);
  /**
   * The function returns an Iterator to the item that corresponds to the item
   * we were looking for. If there is no such member, returns end ().
   * @param data apartment to search
   * @return Iterator to the item that corresponds to the item
   * we were looking for. If there is no such member, returns end ().
   */
  const_iterator find (const Apartment &data) const;
  /**
   * Insertion operator, prints the apartment in the tree in preorder
   * traversal.
   * Each apartmnet will be printed in the format: (x,y)\n
   * @param os reference to std::ostream
   * @param avl tree
   * @return os reference to std::ostream
   */
  friend std::ostream &operator<< (std::ostream &os, const AVL &avl);
 private:
  node *root_;
  /**
   * Check if the given apartment in this tree
   * @param apartment reference to an apartment
   * @return true if if the given apartment in this tree, false o.w.
   */
  bool in_tree (const Apartment &apartment) const;
};

#endif //_AVL_H_
