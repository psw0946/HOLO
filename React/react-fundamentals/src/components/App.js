import React from 'react';
import { hot } from 'react-hot-loader';
// var React = require('react'); 와 같다.

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      name: '',
    };
  }

  render() {
    return (
      <div>
        <button type="button" onClick={() => { this.setState({ name: 'Velopert' }); }}>Click Me</button>
        <h1>Hello!!@C {this.state.name}</h1>
      </div>
    );
  }
}

export default hot(module)(App);
// module.export = App; 와 같다.
