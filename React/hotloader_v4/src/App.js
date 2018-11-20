import React, { Component } from 'react';
import { hot } from 'react-hot-loader';
import logo from './logo.svg';
import './App.css';

class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      name: '',
    };
  }

  render() {
    return (
      <div className="App">
        <header className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
          <button type="button" onClick={() => { this.setState({ name: 'Velopert' }); }}>Click Me</button>
          <p>
            Edit <code>src/App.js</code> and save to reload.
          </p>
          <a
            className="App-link"
            href="https://reactjs.org"
            target="_blank"
            rel="noopener noreferrer"
          >
            Learn React!!! {this.state.name}
          </a>
        </header>
      </div>
    );
  }
}

export default hot(module)(App);
