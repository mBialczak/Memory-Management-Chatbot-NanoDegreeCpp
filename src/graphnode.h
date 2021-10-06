#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include "chatbot.h"
#include <memory>
#include <string>
#include <vector>

// forward declarations
class GraphEdge;

class GraphNode {
  private:
  //// STUDENT CODE
  // data handles (owned)
  // NOTE: task4 change below
  // std::vector<GraphEdge *> _childEdges;  // edges to subsequent nodes
  std::vector<std::unique_ptr<GraphEdge>> _childEdges;

  // data handles (not owned)
  std::vector<GraphEdge*> _parentEdges; // edges to preceding nodes
  ChatBot* _chatBot;

  ////
  //// EOF STUDENT CODE

  // proprietary members
  int _id;
  std::vector<std::string> _answers;

  public:
  // constructor / destructor
  GraphNode(int id);
  ~GraphNode();

  // getter / setter
  int GetID() { return _id; }
  int GetNumberOfChildEdges() { return _childEdges.size(); }
  GraphEdge* GetChildEdgeAtIndex(int index);
  std::vector<std::string> GetAnswers() { return _answers; }
  int GetNumberOfParents() { return _parentEdges.size(); }

  // proprietary functions
  void AddToken(std::string token); // add answers to list
  void AddEdgeToParentNode(GraphEdge* edge);

  //// STUDENT CODE
  // void AddEdgeToChildNode(GraphEdge* edge);
  // NOTE: changed in TASK4:
  // void AddEdgeToChildNode(GraphEdge* edge);
  void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);

  void MoveChatbotHere(ChatBot* chatbot);

  ////
  //// EOF STUDENT CODE

  void MoveChatbotToNewNode(GraphNode* newNode);
};

#endif /* GRAPHNODE_H_ */