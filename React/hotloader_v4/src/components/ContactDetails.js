import React from 'react';
import { hot } from 'react-hot-loader';

class ContactDetails extends React.Component {
  render() {
    const details = (
      <div>
        <p>{this.props.contact.name}</p>
        <p>{this.props.contact.phone}</p>
      </div>
    );
    const blank = (<div>Not Selected</div>);

    return (
      <div>
        <h2>Details</h2>
        {this.props.isSelected ? details : blank}
      </div>
    );
  }
}

// 설정해주지 않으면 this.props.contact가 undefined
ContactDetails.defaultProps = {
  contact: {
    name: '',
    phone: ''
  }
};

export default hot(module)(ContactDetails);
