import React from 'react';
import PropTypes from 'prop-types';
import { hot } from 'react-hot-loader';

class ContactDetails extends React.Component {
  constructor(props) {
    super(props);

    this.state = {
      isEdit: false,
      name: '',
      phone: ''
    };

    this.handleToggle = this.handleToggle.bind(this);
    this.handleChange = this.handleChange.bind(this);
    this.handleEdit = this.handleEdit.bind(this);
  }

  handleToggle() {
    if (!this.state.isEdit) {
      this.setState({
        name: this.props.contact.name,
        phone: this.props.contact.phone
      });
    } else {
      this.handleEdit();
    }

    this.setState({
      isEdit: !this.state.isEdit
    });
    // console.log(this.state.isEdit)
    // (참고) 비동기이기 때문에 setState보다 먼저 수행되어 생각한 값이 출력되지 않을거임
  }

  handleChange(e) {
    let nextState = {};
    nextState[e.target.name] = e.target.value;
    this.setState(nextState);
  }

  handleEdit() {
    this.props.onEdit(this.state.name, this.state.phone);
  }

  render() {
    const details = (
      <div>
        <p>{this.props.contact.name}</p>
        <p>{this.props.contact.phone}</p>
      </div>
    );
    const edit = (
      <div>
        <p>
          <input type="text" name="name" placeholder="name" value={this.state.name} onChange={this.handleChange} />
        </p>
        <p>
          <input type="text" name="phone" placeholder="phone" value={this.state.phone} onChange={this.handleChange} />
        </p>
      </div>
    );
    const view = this.state.isEdit ? edit : details;

    const blank = (<div>Not Selected</div>);

    return (
      <div>
        <h2>Details</h2>
        {this.props.isSelected ? view : blank}
        <p>
          <button onClick={this.handleToggle}>
            {this.state.isEdit ? 'OK' : 'Edit'}
          </button>
          <button onClick={this.props.onRemove}>Remove</button>
        </p>
      </div>
    );
  }
}

// 설정해주지 않으면 this.props.contact가 undefined
ContactDetails.defaultProps = {
  contact: {
    name: '',
    phone: ''
  },
  onRemove: () => { console.error('onRemove not defined'); },
  onEdit: () => { console.error('onEdit not defined'); }
};

ContactDetails.propTypes = {
  contact: PropTypes.object,
  onRemove: PropTypes.func,
  onEdit: PropTypes.func
};

export default hot(module)(ContactDetails);
