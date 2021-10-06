#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <memory>
#include <string>
#include <wx/bitmap.h>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot {
  private:
  // data handles (owned)
  wxBitmap* _image; // avatar image

  // data handles (not owned)
  GraphNode* _currentNode;
  GraphNode* _rootNode;
  ChatLogic* _chatLogic;

  // proprietary functions
  int ComputeLevenshteinDistance(std::string s1, std::string s2);

  public:
  // constructors / destructors
  ChatBot(); // constructor WITHOUT memory allocation
  // NOTE modified original constructor below
  // ChatBot(std::string filename); // constructor WITH memory allocation
  ChatBot(std::string filename, ChatLogic* logic, GraphNode* rootnode);

  ~ChatBot();

  //// STUDENT CODE
  ChatBot(const ChatBot& other) = delete; // NOTE: copy constructor
  ChatBot(ChatBot&& ohter); // MOVE constructor
  ChatBot& operator=(const ChatBot& other) = delete; // NOTE: asignment deleted
  ChatBot& operator=(ChatBot&& other); // MOVE assignment
  //// EOF STUDENT CODE

  // getters / setters
  void SetCurrentNode(GraphNode* node);
  void SetRootNode(GraphNode* rootNode) { _rootNode = rootNode; }
  void SetChatLogicHandle(ChatLogic* chatLogic) { _chatLogic = chatLogic; }
  ChatLogic* GetChatLogicHandle() { return _chatLogic; }
  // NOTE: task2 modification
  // wxBitmap *GetImageHandle() { return _image; }
  wxBitmap* GetImageHandle() { return _image; }
  // communication
  void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
