#include "graphnode.h"
#include "graphedge.h"

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode()
{
  //// STUDENT CODE
  ////

  // delete _chatBot; // NOTE: considered removing  it from the original to fix
  // 0 problem NOT SURE

  ////
  //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge* edge)
{
  // NOTE: consider emplace_back
  _parentEdges.push_back(edge);
}
// NOTE: changed in task 4
// void GraphNode::AddEdgeToChildNode(GraphEdge* edge)
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
  // NOTE: changed in task4
  // _childEdges.push_back(edge);
  _childEdges.emplace_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot* chatbot)
{
  _chatBot = chatbot;
  _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode* newNode)
{
  newNode->MoveChatbotHere(_chatBot);
  _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge* GraphNode::GetChildEdgeAtIndex(int index)
{
  //// STUDENT CODE
  // NOTE: changed in task4
  // return _childEdges[index];
  return _childEdges.at(index).get();
  //// EOF STUDENT CODE
}