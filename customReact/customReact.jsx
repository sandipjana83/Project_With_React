const { Children } = require("react");

function customRender(reactElement, maincontener)
{
  const domElement= document.createElement(reactElement.type);
  domElement.setAttribute('href',reactElement.props.href);
  domElement.setAttribute('target', reactElement.props.target)
  domElement.innerHTML= reactElement.children;

  mainCounter.appendChild(domElement);
}

const ReactElement={
  type :"a",
  props :{
    target: "_main",
    href :"https://google.com",
  },
  children :"Click to process next page",
}
const mainCounter= document.querySelector("#root");
customRender(ReactElement, mainCounter);