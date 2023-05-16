import "./messenger.css";
import Topbar from "../../components/topbar/Topbar";
import Conversations from "../../components/conversations/Conversations";
import Message from "../../components/message/Message";

export default function Messenger() {
  return (
    <>
        <Topbar />
        <div className="messenger">
            <div className="chatMenu">   
                <div className="chatMenuWrapper">
                    <input placeholder="Search for friends" className="chatMenuInput"/>
                    <Conversations/>
                    <Conversations/>
                    <Conversations/>
                    <Conversations/>
                    <Conversations/>

                </div>
            </div>
            <div className="chatBox">    
                <div className="chatBoxWrapper">
                    <div className="chatBoxTop">
                        <Message />
                        <Message />
                        <Message />

                    </div>
                    <div className="chatBoxBottom">
                        
                    </div>
                </div>
            </div>
            <div className="chatOnline"> 
                <div className="chatOnlineWrapper">
                    online
                </div>
            </div>
        </div>
    </>
  );
}



