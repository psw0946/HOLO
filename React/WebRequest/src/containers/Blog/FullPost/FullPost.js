import React, { Component } from 'react';
import axios from 'axios';

import './FullPost.css';

class FullPost extends Component {
  state = {
    loadedPost: null
  }

  componentDidUpdate(prevProps, prevState, snapshot) {
    if (this.props.id) {
      // 이전 것과 비교해서 업데이트 해야한다. 하지 않으면 state 가 업데이트 됨에 따라 무한 루프에 빠짐
      if (!this.state.loadedPost || (this.state.loadedPost && this.state.loadedPost.id !== this.props.id)) {
        axios.get('/posts/' + this.props.id)
          .then(response => {
            this.setState({loadedPost: response.data});
          });
      }
    }
  }

  deletePostHandler = () => {
    axios.delete('/posts/' + this.props.id)
      .then(response => {
        console.log(response);
      });
  }

  render () {
    let post = <p style={{textAlign: 'center'}}>Please select a Post!</p>;
    if (this.props.id) {
      post = <p style={{textAlign: 'center'}}>Loading...!</p>;
    }
    if (this.state.loadedPost) {
      post = (
        <div className="FullPost">
          <h1>{this.state.loadedPost.title}</h1>
          <p>{this.state.loadedPost.body}</p>
          <div className="Edit">
            <button onClick={this.deletePostHandler} className="Delete">Delete</button>
          </div>
        </div>
      );
    }
    return post;
  }
}

export default FullPost;
