////
//// Created by Eli Levinkopf on 20/12/2021.
////
//
//#include "AVL1.h"
//
////************************************//
////*************** node ***************//
////************************************//
//
//AVL::node::node (Apartment data) :
//	data_ (data), left_ (nullptr), right_ (nullptr), height_ (0)
//{}
//
//AVL::node::node (const AVL::node &other) :
//	data_ (other.data_), left_ (nullptr), right_ (nullptr),
//	height_ (other.height_)
//{
//  if (other.get_left ())
//	{
//	  left_ = new node (*other.get_left ());
//	}
//  if (other.get_right ())
//	{
//	  right_ = new node (*other.get_right ());
//	}
//}
//
//AVL::node &AVL::node::operator= (const AVL::node &other)
//{
//  if (this != &other)
//	{
//	  data_ = other.data_;
//	  height_ = other.height_;
//	  node *tmp_left_node = nullptr;
//	  if (other.get_left ())
//		{
//		  tmp_left_node = new node (*other.get_left ());
//		}
//	  delete left_;
//	  left_ = tmp_left_node;
//	  node *tmp_right_node = nullptr;
//	  if (other.get_right ())
//		{
//		  tmp_right_node = new node (*other.get_right ());
//		}
//	  delete right_;
//	  right_ = tmp_right_node;
//	}
//  return *this;
//}
//
//AVL::node::~node ()
//{
//  delete left_;
//  delete right_;
//}
//
//int AVL::node::get_height () const
//{
////  TODO:
////  return ((this) == nullptr ? -1 : (*this).height_);
//  return (*this).height_;
//}
//
//int AVL::node::get_balance_factor () const
//{
////  TODO:
////  if ((this) == nullptr)
////	{
////	  return 0;
////	}
//  if (!right_ && left_)
//	{
//	  return left_->get_height () + 1;
//	}
//  if (right_ && !left_)
//	{
//	  return -(right_->get_height () + 1);
//	}
//  if (!left_ && !right_)
//	{
//	  return get_height ();
//	}
//  return left_->get_height () - right_->get_height ();
//}
//
//AVL::node *AVL::node::insert (AVL::node *new_node)
//{
//  node* tmp = this;
//  if (tmp == nullptr)
//	{
//	  return new_node;
//	}
//  else if (data_ > new_node->get_data ())
//	{
//	  left_ = left_->insert (new_node);
//	}
//  else if (data_ < new_node->get_data ())
//	{
//	  right_ = right_->insert (new_node);
//	}
//  else
//	{
//	  return nullptr;
//	}
////	2
//  set_height ();
//// 3
////TODO: avl_balance (new_node);
//  return avl_balance ();
//}
//
//AVL::node *AVL::node::erase_node (const Apartment &apartment)
//{
////  TODO:
////  if ((this) == nullptr)
////	{
////	  return this;
////	}
//  if (data_ > apartment)
//	{
//	  left_ = left_->erase_node (apartment);
//	}
//  else if (data_ < apartment)
//	{
//	  right_ = right_->erase_node (apartment);
//	}
//  else
//	{
//	  if (left_ && right_) // 2 children
//		{ // find the successor
//		  Apartment successor_data = right_->find_successor_in_sub_tree ();
//		  data_ = successor_data; // replace between data_ and successor.data_
//		  right_ = right_->erase_node (successor_data);
//		}
//	  else if ((!right_ || !left_)) // one or zero child
//		{  // save the node to delete
//		  node *node_to_delete = right_ ? right_ : left_;
//		  if (!left_ && !right_){
//			height_ --;
//		  }
//		  if (node_to_delete == nullptr) // no child
//			{
//			  return nullptr;
//			}
//		  else // one child
//			{
//			  *this = *node_to_delete;
//			}
////	  delete node_to_delete; //delete the node
//		}
//	}
////	TODO:
////  if ((this) == nullptr) // end of tree
////	{
////	  return this;
////	}
////================
//  set_height ();
////  TODO:   return avl_balance (this);
//  return avl_balance ();
//}
//
//AVL::node *AVL::node::avl_balance ()
//{
//  if (get_balance_factor () == 2)
//	{
////	  if (left_->get_data () > node_to_balance->get_data ())
//	  if (left_->get_balance_factor () >= 0)
//		{
////		  LL
//		  return right_rotate ();
//		}
//	  else
//		{
////		  LR
//		  left_ = left_->left_rotate ();
//		  return right_rotate ();
//		}
//	}
//  if (get_balance_factor () == -2)
//	{
////	  TODO: check right_->get_data () *<* node_to_balance->get_data ()
////	  if (right_->get_data () > node_to_balance->get_data ())
//	  if (right_->get_balance_factor () <= 0)
//		{
////		  RR
//		  return left_rotate ();
//		}
//	  else
//		{
////		  RL
//		  right_ = right_->right_rotate ();
//		  return left_rotate ();
//		}
//	}
//  return this;
//}
//
//void AVL::node::set_height ()
//{
////  TODO:
////  if ((this) == nullptr)
////	{
////	  return;
////	}
//  if (!left_ && !right_)
//	{
//	  height_ = 0;
//	  return;
//	}
//  if (!left_ && right_)
//	{
////	  if (right_)
////		{
//	  height_ = right_->get_height () + 1;
////		}
////	  return;
//	}
//  if (left_ && !right_)
//	{
////	  if (left_)
////		{
//	  height_ = left_->get_height () + 1;
////		}
//	}
//  if (left_ && right_)
//	{
//	  height_ = std::max (left_->get_height (), right_->get_height ()) + 1;
//	}
//}
//
////AVL::node *AVL::node::right_rotate ()
////{
////  node *new_sub_root = left_;
////  left_ = new_sub_root->right_;
////  new_sub_root->right_ = this;
////  new_sub_root->set_height ();
////  left_->set_height ();
////  return new_sub_root;
////}
////
////AVL::node *AVL::node::left_rotate ()
////{
////  node *new_sub_root = right_;
////  right_ = new_sub_root->left_;
////  new_sub_root->left_ = this;
////  new_sub_root->set_height ();
////  right_->set_height ();
////  return new_sub_root;
////}
//
//AVL::node *AVL::node::right_rotate ()
//{
//  node *new_sub_root = left_;
//  left_ = new_sub_root->right_;
//  new_sub_root->right_ = this;
//  set_height();
//  new_sub_root->set_height ();
//  if (left_)
//	{
//	  left_->set_height ();
//	}
//  return new_sub_root;
//}
//
//AVL::node *AVL::node::left_rotate ()
//{
//  node *new_sub_root = right_;
//  right_ = new_sub_root->left_;
//  new_sub_root->left_ = this;
//  set_height();
//  new_sub_root->set_height ();
//  if (right_)
//	{
//	  right_->set_height ();
//	}
//  return new_sub_root;
//}
//
////AVL::node *AVL::node::right_rotate ()
////{
////  node *new_sub_root = left_;
////  if (new_sub_root){
////	  left_ = new_sub_root->right_;
////	}
////  else{
////	  left_ = new_sub_root;
////	}
////  if (new_sub_root){
////	  new_sub_root->right_ = this;
////	}
////  new_sub_root->set_height ();
////  left_->set_height ();
////  return new_sub_root;
////}
////
////AVL::node *AVL::node::left_rotate ()
////{
////  node *new_sub_root = right_;
////  if (new_sub_root){
////	  right_ = new_sub_root->left_;
////	}
////  else{
////	  right_ = new_sub_root;
////	}
////  if (new_sub_root){
////	  new_sub_root->left_ = this;
////	}
////  new_sub_root->set_height ();
////  right_->set_height ();
////  return new_sub_root;
////}
//
//Apartment AVL::node::find_successor_in_sub_tree ()
//{
//  node *min_node = this;
//  while (min_node->left_)
//	{
//	  min_node = min_node->left_;
//	}
//  return min_node->data_;
//}
//
////***********************************//
////*************** AVL ***************//
////***********************************//
//
//AVL::AVL () : root_ (nullptr)
//{}
//
//AVL::AVL (const AVL &other) : root_ (new node (*other.root_))
//{}
//
//AVL::AVL (std::vector<std::pair<double, double>> coordinates) : root_ ()
//{
//  root_ = nullptr;
//  for (auto pair: coordinates)
//	{
//	  Apartment apartment (pair);
//	  insert (apartment);
//	}
//}
//
//AVL::~AVL ()
//{ delete root_; }
//
//AVL &AVL::operator= (const AVL &other)
//{
//  if (this != &other)
//	{
//	  delete root_;
////	  node *tmp_root = new node (*other.root_);
////	  TODO: delete
//
////	  root_ = tmp_root;
//	  root_ = new node (*other.root_);
//	}
//  return *this;
//}
//
//void AVL::insert (const Apartment &apartment)
//{
//  node *new_node = new node (apartment);
//  if (!root_)
//	{
//	  root_ = new_node;
//	}
//  else
//	{
//	  root_ = root_->insert (new_node);
//	}
//
//}
//
//void AVL::erase (const Apartment &apartment)
//{
//  if (in_tree (apartment))
//	{
//	  root_ = root_->erase_node (apartment);
//	}
//}
//
//AVL::iterator AVL::begin ()
//{ return root_; }
//
//AVL::iterator AVL::end ()
//{ return nullptr; }
//
//AVL::const_iterator AVL::begin () const
//{ return root_; }
//
//AVL::const_iterator AVL::end () const
//{ return nullptr; }
//
//AVL::const_iterator AVL::cbegin () const
//{ return root_; }
//
//AVL::const_iterator AVL::cend () const
//{ return nullptr; }
//
//AVL::iterator AVL::find (const Apartment &data)
//{
//  Iterator it (root_);
//  if (!in_tree (data))
//	{
//	  return end ();
//	}
//  return it.bst (data);
//}
//
//AVL::const_iterator AVL::find (const Apartment &data) const
//{
//  ConstIterator it (root_);
//  if (!in_tree (data))
//	{
//	  return end ();
//	}
//  return it.bst (data);
//}
//
//bool AVL::in_tree (const Apartment &apartment) const
//{
//  node *cur_node = root_;
//  while (cur_node)
//	{
//	  if (cur_node->data_ == apartment)
//		{
//		  return true;
//		}
//	  if (cur_node->data_ > apartment && cur_node->left_)
//		{
//		  cur_node = cur_node->left_;
//		}
//	  else if (cur_node->data_ < apartment && cur_node->right_)
//		{
//		  cur_node = cur_node->right_;
//		}
//	  else
//		{
//		  return false;
//		}
//	}
//  return false;
//}
//
//AVL::Iterator AVL::Iterator::bst (Apartment apartment)
//{
//  if ((this)->nodes_stack_.top () == nullptr
//	  || nodes_stack_.top ()->data_ == apartment)
//	{
//	  return *this;
//	}
//  if (nodes_stack_.top ()->data_ > apartment)
//	{
//	  return (++(*this)).bst (apartment);
//	}
//  return (++(++(*this))).bst (apartment);
//}
//
//std::ostream &operator<< (std::ostream &os, const AVL &avl)
//{
//  for (const auto &it: avl)
//	{
//	  std::cout << it;
//	}
//  return os;
//}
//
////****************************************//
////*************** Iterator ***************//
////****************************************//
//
//AVL::Iterator::Iterator (node *root) : root_ (root)
//{
//  if (root_)
//	{
//	  root_ = new node (*root);
//	}
//  if (root_)
//	{
//	  nodes_stack_.push (root_);
//	}
//}
//
//AVL::Iterator::pointer AVL::Iterator::operator-> ()
//{ return &nodes_stack_.top ()->data_; }
//
//Apartment &AVL::Iterator::operator* ()
//{ return nodes_stack_.top ()->data_; }
//
//AVL::Iterator &AVL::Iterator::operator++ ()
//{
//  node *top_node = nodes_stack_.top ();
//  nodes_stack_.pop ();
//  if (top_node->right_)
//	{
//	  nodes_stack_.push (top_node->right_);
//	}
//  if (top_node->left_)
//	{
//	  nodes_stack_.push (top_node->left_);
//	}
//  if (nodes_stack_.empty ())
//	{
//	  root_ = nullptr;
//	  return *this;
//	}
//  return *this;
//}
//
//AVL::Iterator AVL::Iterator::operator++ (int)
//{
//  Iterator it = *this;
//  ++(*this);
//  return it;
//}
//
//bool AVL::Iterator::operator== (const AVL::Iterator &rhs) const
//{
//  std::stack<node *> tmp_1, tmp_2, dst_1, dst_2;
//  copy_reverse (this->nodes_stack_, tmp_1);
//  copy_reverse (tmp_1, dst_1);
//  copy_reverse (rhs.nodes_stack_, tmp_2);
//  copy_reverse (tmp_2, dst_2);
//
//  if (nodes_stack_.size () != rhs.nodes_stack_.size ())
//	{
//	  return false;
//	}
//  while (!dst_1.empty ())
//	{
//	  if (dst_1.top () == dst_2.top ())
//		{
//		  dst_1.pop ();
//		  dst_2.pop ();
//		}
//	  else
//		{
//		  return false;
//		}
//	}
//  return true;
////  return nodes_stack_ == rhs.nodes_stack_;
//}
//void AVL::Iterator::copy_reverse
//	(std::stack<node *> src, std::stack<node *> dst) const
//{
//  while (!src.empty ())
//	{
//	  dst.push (src.top ());
//	  src.pop ();
//	}
//}
//
//bool AVL::Iterator::operator!= (const AVL::Iterator &rhs) const
//{
//  return !(*this == rhs);
//}
//
////****************************************//
////*************** ConstIterator **********//
////****************************************//
//
//AVL::ConstIterator::ConstIterator (AVL::node *root) : root_ (root)
//{
//  if (root_)
//	{
//	  nodes_stack_.push (root_);
//	}
//}
//
//AVL::ConstIterator::ConstIterator (const AVL::Iterator &it) : root_ (it.root_)
//{
//  if (root_)
//	{
//	  nodes_stack_.push (root_);
//	}
//}
//
//AVL::ConstIterator::pointer AVL::ConstIterator::operator-> ()
//{ return &nodes_stack_.top ()->data_; }
//
//const Apartment &AVL::ConstIterator::operator* ()
//{ return nodes_stack_.top ()->data_; }
//
//AVL::ConstIterator &AVL::ConstIterator::operator++ ()
//{
//  node *top_node = nodes_stack_.top ();
//  nodes_stack_.pop ();
//  if (top_node->right_)
//	{
//	  nodes_stack_.push (top_node->right_);
//	}
//  if (top_node->left_)
//	{
//	  nodes_stack_.push (top_node->left_);
//	}
//  return *this;
//}
//
//AVL::ConstIterator AVL::ConstIterator::operator++ (int)
//{
//  ConstIterator it = *this;
//  ++(*this);
//  return it;
//}
//
//bool AVL::ConstIterator::operator== (const AVL::ConstIterator &rhs) const
//{ return nodes_stack_ == rhs.nodes_stack_; }
//
//bool AVL::ConstIterator::operator!= (const AVL::ConstIterator &rhs) const
//{ return !(*this == rhs); }
//
//AVL::ConstIterator AVL::ConstIterator::bst (Apartment apartment)
//{
//  if ((this)->nodes_stack_.top () == nullptr
//	  || nodes_stack_.top ()->data_ == apartment)
//	{
//	  return *this;
//	}
//  if (nodes_stack_.top ()->data_ > apartment)
//	{
//	  return (++(*this)).bst (apartment);
//	}
////	TODO: return (++(++(*this))).bst (apartment);
//  return ((++(*this))).bst (apartment);
//}
