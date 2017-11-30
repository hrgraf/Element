
#ifndef EL_VIEW_HELPERS_H
#define EL_VIEW_HELPERS_H

#include "ElementApp.h"
#include "engine/GraphNode.h"
#include "session/Session.h"

namespace Element {

class ContentComponent;
class Globals;
class Node;

namespace ViewHelpers {

/** Draws a common text row in a normal list box */
void drawBasicTextRow (const String& text, Graphics& g, int w, int h, bool selected, int padding = 10);

/** Draws a common text row in a horizontal list box */
void drawVerticalTextRow (const String& text, Graphics& g, int w, int h, bool selected);

/** Finds the content component by traversing parent component(s) */
ContentComponent* findContentComponent (Component* c);

/** Get World */
Globals* getGlobals (Component* c);

/** Get Session */
SessionPtr getSession (Component* c);

/** Invoke a command directly */
bool invokeDirectly (Component* c, const int commandID, bool async);
    
/** Post a message to AppController
 
    This works by finding the ContentComponent and letting it handle message posting.
    If the content component wasn't found, then the passed in Message will be deleted
    immediately.  DO NOT keep a reference to messages passed in here 
 */
void postMessageFor (Component*, Message*);

GraphNodePtr findGraphNodeFor (Component*, const Node&);

void presentPluginWindow (Component*, const Node&);
void closePluginWindows (Component*, const bool visible = true);

}
}



#endif  // EL_VIEW_HELPERS_H
