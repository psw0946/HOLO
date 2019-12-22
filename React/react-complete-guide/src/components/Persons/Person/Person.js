import React, { Component } from 'react';
import PropTypes from 'prop-types';
import classes from './Person.css';
import Aux from '../../../hoc/Aux';
import withClass from "../../../hoc/withClass";
import AuthContext from '../../../context/auth-context';

class Person extends Component {
  constructor(props) {
    super(props);
    this.inputElementRef = React.createRef();
  }

  // static can be accessed from outside without the need to instantiate an object based on this class
  // recommended by instructor because it can be used not only in 'componentDidMount' but also in 'render' function
  static contextType = AuthContext;

  componentDidMount() {
    // this.inputEl.focus();
    this.inputElementRef.current.focus();
    console.log(this.context.authenticated);
  }

  render() {
    console.log('[Person.js] rendering...');
    return (
      <Aux>
        {this.context.authenticated ? <p>Authenticated!</p> : <p>Please log in!</p>}
        <p onClick={this.props.click}>I'm {this.props.name} and I am {this.props.age} years old</p>
        <p>{this.props.children}</p>
        <input
          type="text"
          onChange={this.props.changed}
          value={this.props.name}
          // ref={(inputEl) => { this.inputEl = inputEl; }} (older)
          ref={this.inputElementRef}
        />
      </Aux>
    );
  }
}

Person.propTypes = {
  click: PropTypes.func,
  name: PropTypes.string,
  age: PropTypes.number,
  changed: PropTypes.func,
};

export default withClass(Person, classes.Person);
