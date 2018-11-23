import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './components/App';
import * as serviceWorker from './serviceWorker';
import { createStore } from 'redux';
import reducers from './reducers';
// import * as actions from './actions';
import { Provider } from 'react-redux';

const store = createStore(reducers);

/*
console.log(store.getState());
const unsubscribe = store.subscribe(() => console.log(store.getState()));
store.dispatch(actions.increment());
store.dispatch(actions.increment());
store.dispatch(actions.decrement());
store.dispatch(actions.setColor([200, 200, 200]));

unsubscribe(); // store의 subscribe 메소드가 unsubscribe하는 함수를 반환

store.dispatch(actions.setColor([210, 210, 210]));
*/

ReactDOM.render(
  <Provider store={store}>
    <App />
  </Provider>,
  document.getElementById('root')
);

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: http://bit.ly/CRA-PWA
serviceWorker.unregister();
