import * as React from "react";
import * as ReactDOM from "react-dom";

export function render<P>(C: React.FunctionComponent<P>, props: Readonly<P>, _parent: Element | Document | ShadowRoot | DocumentFragment | string, replaceNode?: Element | Text) {
    const parent = typeof _parent === "string" ? document.getElementById(_parent) : _parent;
    ReactDOM.render(React.createElement(C, props), parent, replaceNode);
}

export function svgRender<P>(C: React.FunctionComponent<P>, props: Readonly<P>, parent: Element | Document | ShadowRoot | DocumentFragment, replaceNode?: Element | Text) {
    ReactDOM.render(React.createElement("svg", null, React.createElement(C, props)), parent, replaceNode);
}

export function unrender(parent: Element | Document | ShadowRoot | DocumentFragment) {
    if (parent) {
        ReactDOM.unmountComponentAtNode(parent);
    }
}
