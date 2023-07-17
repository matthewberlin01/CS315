#include <iostream>
#include "TagParser.hpp"
using namespace std;

void TagParser::parseTags(vector<Token> &tokens){
    for(int i = 0; i < tokens.size(); i++){
        if(tokens.at(i).isOpenTag()){
            if(i != tokens.size()){
                if(tokens.at(i + 1).isCloseAngleBracket() || tokens.at(i + 1).isCloseStandAloneTag()){
                    theStack.push(tokens.at(i));
                }
                else{
                    malFormedTags.push(tokens.at(i));
                }
            }
            else{
                malFormedTags.push(tokens.at(i));
            }
        }
        else if(tokens.at(i).isCloseTag()){
            if(!theStack.empty()){
                if(theStack.top().isOpenTag() && theStack.top().isCloseAngleBracket() && theStack.top().getTagName() == tokens.at(i).getTagName()){
                    if(i != tokens.size()){
                        if(tokens.at(i + 1).isCloseAngleBracket()){
                            wellFormedTags[theStack.top().getTagName()].push(theStack.top());
                            theStack.pop();
                            wellFormedTags[tokens.at(i).getTagName()].push(tokens.at(i));
                            i++;    //We can skip the next token since we've already confirmed that the Close tag has a close angle bracket after this.
                        }
                    }
                }
                else if(i != tokens.size()){
                    if(tokens.at(i + 1).isCloseAngleBracket()){
                        if(theStack.findTag(theStack, tokens.at(i))){
                            tokens.at(i).isImproperlyNested() = true;
                            theStack.removeTag(theStack, malFormedTags, tokens.at(i));
                            i++;
                        }
                        else{
                            tokens.at(i).isCloseAngleBracket() = true;
                            malFormedTags.push(tokens.at(i));
                        }
                    }
                    else{
                        malFormedTags.push(tokens.at(i));
                    }
                }
                else{
                    malFormedTags.push(tokens.at(i));
                }
            }
            else{
                if(i != tokens.size()){
                    if(tokens.at(i + 1).isCloseAngleBracket()){
                        tokens.at(i).isCloseAngleBracket() = true;
                        malFormedTags.push(tokens.at(i));
                    }
                }
                else{
                    malFormedTags.push(tokens.at(i));
                }
            }
        }
        else if(tokens.at(i).isCloseStandAloneTag()){
            if(theStack.top().isOpenTag()){
                wellFormedTags[theStack.top().getTagName()].push(theStack.top());
                wellFormedTags[theStack.top().getTagName()].push(tokens.at(i));
                theStack.pop();
            }
            else{
                malFormedTags.push(tokens.at(i));
            }
        }
        else if(tokens.at(i).isOpenAngleBracket()){
            malFormedTags.push(tokens.at(i));
        }
        else if(tokens.at(i).isCloseAngleBracket()){
            //We don't need to see if the top of the stack is a close tag even though close tags also have
            // close angle brackets since only open tags are pushed onto theStack.
            if(!theStack.empty()){
                if(theStack.top().isOpenTag() && !theStack.top().isCloseAngleBracket()){
                    Token updatedToken = theStack.top();
                    updatedToken.isCloseAngleBracket() = true;
                    theStack.pop();
                    theStack.push(updatedToken);
                }
                else if(malFormedTags.top().isCloseTag()){
                    tokens.at(i).isMalformedCloseAngleBracket() = true;
                    malFormedTags.push(tokens.at(i));
                }
                else{
                    malFormedTags.push(tokens.at(i));
                }
            }
            else if(malFormedTags.top().isCloseTag()){
                tokens.at(i).isMalformedCloseAngleBracket() = true;
                malFormedTags.push(tokens.at(i));
            }
            else{
                malFormedTags.push(tokens.at(i));
            }
        }
        else{
            cout << "Error, tag token made but is not an open, close, stand alone tag or an open or closed angle bracket." << endl;
            exit(1);
        }
    }
    if(!theStack.empty()){
        //No need to go through cases here, anything left on the stack at this point must be an open tag since that is
        //the only tag that is pushed onto the stack
        while(!theStack.empty()){
            malFormedTags.push(theStack.top());
            theStack.pop();
        }
    }
}

void TagParser::printTags(){
    for(int i = 0; i < malFormedTags.size(); i++){
        malFormedTags.at(i).printBadTag();
    }
    cout << endl;
    cout << "The following is a list of well-formed HTML tags." << endl;
    cout << endl;
    for(auto theTags = wellFormedTags.begin(); theTags != wellFormedTags.end(); theTags++){
        if((theTags->second.size() / 2) > 1){
            cout << theTags->first << " appeared in the following " << (theTags->second.size() / 2) << " locations." << endl;
        }
        else{
            cout << theTags->first << " appeared in the following location." << endl;
        }

        for(int i = 0; i < theTags->second.size(); i++){
            theTags->second.at(i).printGoodTag();
        }
        cout << endl;
    }
}

